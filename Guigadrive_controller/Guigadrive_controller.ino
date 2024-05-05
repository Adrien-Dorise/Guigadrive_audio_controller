/*
  Guigadrive controller main script
  Author: Adrien Dorise
  Date: 05/05/2024

  This script convert audio input into Gamepad actions.
  Because the audio input needs to stabilise, a calibration phase is needed the first 10 seconds of the program.
  This calibration sets the baseline threshold at which a note is detected.

  It uses: - FFT library: Copyright (C) 2018 Enrique Condés and Ragnar Ranøyen Homb
                          Copyright (C) 2020 Bim Overbohm (template, speed improvements)
           - BLE Gamepad library: https://github.com/lemmingDev/ESP32-BLE-Gamepad
*/

#include <Arduino.h>
#include "arduinoFFT.h"
#include <BleGamepad.h>


// FFT parameters
#define CHANNEL A14
#define ON_LED 4
#define FREQ_LED 17
#define CALIBRATION 2000
const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = 350; //Hz, must be less than 10000 due to ADC
unsigned int sampling_period_us;
unsigned long microseconds;

// FFT initialisation
double vReal[samples];
double vImag[samples];
double frequency;
double calibration;
double max_value;
ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, samples, samplingFrequency);
#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

// Keyboard
BleGamepad bleGamepad("Guigadrive IN", "Doriens", 100);

void setup()
{
  sampling_period_us = round(1000000*(1.0/samplingFrequency));
  pinMode(ON_LED,OUTPUT);
  digitalWrite(ON_LED,HIGH);
  
  Serial.begin(115200);
  while(!Serial);
  bleGamepad.begin();
  Serial.println("Ready");
  
  pinMode(FREQ_LED,OUTPUT);
  digitalWrite(FREQ_LED,HIGH);
  calibration = calibrate();
  //calibration = 2000;
  Serial.println(calibration);
  delay(1000);
  Serial.println("Starting controller");
}



void loop()
{
  //Verify if audio signal is higher than set threshold
  int max = 0;
  for(int i=0; i<32; i++)
  {
    int value = analogRead(CHANNEL); 
    if(value > max)
    {
      max = value;
    }
  }

  //Process frequency
  if(max >= calibration*1.13)
  {
    microseconds = micros();
    for(int i=0; i<samples; i++)
    {
        vReal[i] = analogRead(CHANNEL);
        vImag[i] = 0;
        while(micros() - microseconds < sampling_period_us){
          //empty loop
        }
        microseconds += sampling_period_us;
    }
    FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);	/* Weigh data */
    FFT.compute(FFTDirection::Forward); /* Compute FFT */
    FFT.complexToMagnitude(); /* Compute magnitudes */
    frequency = get_frequency(vReal, (samples >> 1), SCL_FREQUENCY);
    Serial.print(frequency);
    Serial.println(" Hz");
  }
  else
  {
    frequency = 0;
    digitalWrite(FREQ_LED, LOW);
  }

  //Process output
  press_key(frequency);
  delay(20); /* Repeat after delay */
  
}

void press_key(double frequency)
{
  if(frequency == 0)
  {
    release_all();
  }

  if(69 <= frequency && frequency <= 73) //1rst string case 2
  {
    digitalWrite(FREQ_LED, HIGH);
    bleGamepad.press(BUTTON_1);
  }
  if(100 <= frequency && frequency <= 106) //2nd string case 2
  {
    digitalWrite(FREQ_LED, HIGH);
    bleGamepad.press(BUTTON_2);
  }
  if(85 <= frequency && frequency <= 90) //2nd string case 3
  {
    digitalWrite(FREQ_LED, HIGH);
    bleGamepad.press(BUTTON_3);
  }
  if(57 <= frequency && frequency <= 62) //3rd string case 5
  {
    digitalWrite(FREQ_LED, HIGH);
    bleGamepad.press(BUTTON_4);
  }
  if(140 <= frequency && frequency <= 145) //3rd string case 2
  {
    digitalWrite(FREQ_LED, HIGH);
    bleGamepad.press(BUTTON_5);
  }
  if(167 <= frequency && frequency <= 171) //3rd string case 3
  {
    digitalWrite(FREQ_LED, HIGH);
    bleGamepad.press(BUTTON_6);
  }
  if(41 <= frequency && frequency <= 45) //2nd string case 5
  {
    digitalWrite(FREQ_LED, HIGH);
    bleGamepad.press(BUTTON_7);
  }

}


void release_all()
{
  bleGamepad.release(BUTTON_1);
  bleGamepad.release(BUTTON_2);
  bleGamepad.release(BUTTON_3);
  bleGamepad.release(BUTTON_4);
  bleGamepad.release(BUTTON_5);
  bleGamepad.release(BUTTON_6);
  bleGamepad.release(BUTTON_7);
}

double calibrate()
{
  for(int i=0;i<6;i++)
  {
    analogRead(CHANNEL);
    delay(1000);
    digitalWrite(FREQ_LED, LOW);
    analogRead(CHANNEL);
    delay(1000);
    digitalWrite(FREQ_LED, HIGH);
  }

  digitalWrite(ON_LED, LOW);
  double sum = 0;
  for(int i=0; i<4096; i++)
  {
    int value = analogRead(CHANNEL);
    sum += value;
    Serial.println(value);
  }
  delay(500);
  digitalWrite(ON_LED, HIGH);
  digitalWrite(FREQ_LED, LOW);
  return sum / 4096;
}

double get_frequency(double *vData, uint16_t bufferSize, uint8_t scaleType)
{
  double max = 0;
  double freq = 20;
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    double abscissa;
    /* Print abscissa value */
    switch (scaleType)
    {
      case SCL_INDEX:
        abscissa = (i * 1.0);
	break;
      case SCL_TIME:
        abscissa = ((i * 1.0) / samplingFrequency);
	break;
      case SCL_FREQUENCY:
        abscissa = ((i * 1.0 * samplingFrequency) / samples);
	break;
    }
    if(abscissa >= freq && vData[i] >= max)
    {
      freq = abscissa;
      max = vData[i];
    }

  }
  return freq;
}

void PrintVector(double *vData, uint16_t bufferSize, uint8_t scaleType)
{
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    double abscissa;
    /* Print abscissa value */
    switch (scaleType)
    {
      case SCL_INDEX:
        abscissa = (i * 1.0);
	break;
      case SCL_TIME:
        abscissa = ((i * 1.0) / samplingFrequency);
	break;
      case SCL_FREQUENCY:
        abscissa = ((i * 1.0 * samplingFrequency) / samples);
	break;
    }
    Serial.print(abscissa, 6);
    if(scaleType==SCL_FREQUENCY)
      Serial.print("Hz");
    Serial.print(" ");
    Serial.println(vData[i], 4);
  }
  Serial.println();
}
#include "arduinoFFT.h"
#include "RunningAverage.h"
 
#define SAMPLES 512           //Must be a power of 2 {1,2,4,8,16,32,64,128,256,512,1024,2048}
#define SAMPLING_FREQUENCY 3000 //Hz, must be less than 10000 due to ADC
#define TIMEWINDOWSIZE 8

 
arduinoFFT FFT = arduinoFFT();
RunningAverage avg(TIMEWINDOWSIZE);
 
unsigned int sampling_period_us;
unsigned long microseconds;
unsigned long maxAmplitude;
unsigned long maxFreq;

bool isZeroFreqFound;
unsigned long minAmplitude = 0;

int measure;
double vReal[SAMPLES];
double vImag[SAMPLES];



 
void setupFFT() {
    sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));

    //We use registers instead of analogRead() for faster ADC monitoring (https://forum.arduino.cc/t/speed-of-analogread/134428/2)
    int t=analogRead(0);
    ADC->ADC_MR |= 0x80; // these lines set free running mode on adc 7 (pin A0)
    ADC->ADC_CR=2;
    ADC->ADC_CHER=0x80;

    //float f=Q_FFT(data,256,100);
    isZeroFreqFound = false;
}


 
unsigned long findFreq() {
    /*SAMPLING*/ 
    for(int i=0; i<SAMPLES+TIMEWINDOWSIZE; i++)
    {
        microseconds = micros();    //Overflows after around 70 minutes!
        while((ADC->ADC_ISR & 0x80)==0); // wait for conversion
        measure=ADC->ADC_CDR[7];

        
        avg.addValue(measure);
        if(i>=TIMEWINDOWSIZE)
        {
          vReal[i-TIMEWINDOWSIZE] = avg.getAverage();
          vImag[i-TIMEWINDOWSIZE] = 0;
        }
        while(micros() < (microseconds + sampling_period_us)){}
    }
    avg.clear();

    /*FFT*/
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    //double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);

    maxFreq = 0;
    if(!isZeroFreqFound)
    {
      /*Get noise level when not playing */
      minAmplitude = vReal[2];
      for(int i=2; i<(SAMPLES/2); i++) //We do not start at 0Hz as they are the dominant peaks while not of interest
      {
          if(minAmplitude < vReal[i])
          {
            minAmplitude = vReal[i];
          }
      }
      isZeroFreqFound = true;
      minAmplitude = minAmplitude * 2.0;
    }
    else
    {
      maxAmplitude = minAmplitude;
      maxFreq = 0;
      for(int i=2; i<(SAMPLES/2); i++)
      {
          if(maxAmplitude < vReal[i])
          {
            maxAmplitude = vReal[i];
            maxFreq = (i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES;
          }
          //View all these three lines in serial terminal to see which frequencies has which amplitudes
           
          //Serial.print((i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES, 1);
          //Serial.print("Hz / ");
          //Serial.println(vReal[i], 1);    //View only this line in serial plotter to visualize the bins
      }
      
    }
    return maxFreq;
    
}

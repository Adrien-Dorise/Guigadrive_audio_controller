#include "Keyboard.h"

#define keyW 87
#define keyA 65
#define keyS 83
#define keyD 68

bool isButtonPressed;

void setupInput()
{
  Keyboard.begin();
  isButtonPressed = false;
}


int convertFreqToInput(unsigned long freq)
{
  int input = 0;
  
  if(freq>100 && freq<=210)
  {
    input = keyW;
  }
  else if(freq>210 && freq<=250)
  {
    input = keyA;
  }
  else if(freq>250 && freq<=300)
  {
    input = keyS;
  }
  else if(freq>300 && freq<=350)
  {
    input = keyD;
  }
  else
  {
    input = 0;
  }
  return input;
}



void makeInput(int button) 
{
  if(button == 0 && isButtonPressed)
  {
    Keyboard.releaseAll();
    Serial.println("Button released");
    isButtonPressed = false;
  }
  if(button != 0)
  {
    Keyboard.press(button);
    Serial.print("Button pressed: ");
    Serial.println(button);
    isButtonPressed = true;
  }

}

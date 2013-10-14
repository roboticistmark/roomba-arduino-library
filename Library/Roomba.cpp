#include "Arduino.h"
#include "Roomba.h"

// default constructor
Roomba::Roomba()
{
	// reset the LED bytes
	LEDByte1 = 0;
	LEDByte2 = 0;
	LEDByte3 = 0;
}

void Roomba::DemoPLED(int stepsize){
  byte color = 0;
  byte intensity = 0;
  
  while(intensity <= (255 - stepsize)){
    SetPLEDColor(color);
    color+= stepsize;
    if (color >= (255 - stepsize)){
      color = 0;
      SetPLEDIntensity(intensity);
      intensity+= stepsize;
    }
  }
  return;
}


void Roomba::SetPLEDIntensity(byte intensity){
  LEDByte3 = intensity;
  UpdateLEDs();
}

void Roomba::SetPLEDColor(byte color){
  LEDByte2 = color;
  UpdateLEDs();
}

void Roomba::SetSLEDOff(){
  LEDByte1 = (LEDByte1 && 0x11001111);
  UpdateLEDs();
}

void Roomba::SetSLEDGreen(){
  LEDByte1 = (LEDByte1 && 0x11001111);
  LEDByte1 = (LEDByte1 || 0x00100000);
  UpdateLEDs();
}

void Roomba::SetSLEDRed(){
  LEDByte1 = (LEDByte1 && 0x11001111);
  LEDByte1 = (LEDByte1 || 0x00010000);
  UpdateLEDs();
}

void Roomba::SetSLEDAmber(){
  LEDByte1 = (LEDByte1 || 0x00110000);
  UpdateLEDs();
}


// private routine to update the LED Bytes directly
void Roomba::UpdateLEDs(){
  mySerial.write(139);
  delay(10);
  mySerial.write(LEDByte1);
  delay(10);
  mySerial.write(LEDByte2);
  delay(10);
  mySerial.write(LEDByte3);
}
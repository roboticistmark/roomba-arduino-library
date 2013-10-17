#include "Arduino.h"
#include "Roomba.h"
#include "SoftwareSerial.h"

// default constructor
Roomba::Roomba(int serialRX, int serialTX, int baud): mySerial(serialRX, serialTX)
{
	// reset the LED bytes
	LEDByte1 = 0;
	LEDByte2 = 0;
	LEDByte3 = 0;
	
	// reset the motor byte
	MotorByte = 0;
	
	// default baud rate for Roomba is 57600
	mySerial.begin(57600);
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


// mode commands
void Roomba::Start(){
  mySerial.write(128);
}

void Roomba::Command(){
  mySerial.write(130);
}

void Roomba::Safe(){
  mySerial.write(131);
}

void Roomba::Full(){
	mySerial.write(132);
}

void Roomba::Power(){
	mySerial.write(133);
}
	
void Roomba::Spot(){
	mySerial.write(134);
}

// cleaning commands
void Roomba::Clean(){
	mySerial.write(135);
}

void Roomba::Max(){
	mySerial.write(136);
}


// Sensor functions

int Roomba::PollSensors(byte *sensorData, byte package){
	
	// counter variable
	int i = 0;
	int timeout = 0;
	
	// request the data
	mySerial.write(142);
	delay(10);
	mySerial.write(package);
	
	// wait some time for the data to appear
	while(!mySerial.available() && (timeout < 100)){
		delay(10);
		++timeout;
	}
	// collect the data
	while(mySerial.available()){
		sensorData[i] = mySerial.read();
		i++;
	}
	// return the size of the data package
	return i;
}

// 1st package
int Roomba::GetRBump(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[0] & B00000001);
	else
		return -1;	
}

int Roomba::GetLBump(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[0] & B00000010);
	else
		return -1;	
}

int Roomba::GetRWheelDrop(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[0] & B00000100);
	else
		return -1;	
}

int Roomba::GetCWheelDrop(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[0] & B00001000);
	else
		return -1;	
}
int Roomba::GetLWheelDrop(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[0] & B00010000);
	else
		return -1;	
}

int Roomba::GetWall(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[1]);
	else
		return -1;	
}

int Roomba::GetLCliff(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[2]);
	else
		return -1;	
}

int Roomba::GetFLCliff(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[3]);
	else
		return -1;	
}

int Roomba::GetFRCliff(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[4]);
	else
		return -1;	
}

int Roomba::GetRCliff(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[5]);
	else
		return -1;	
}

int Roomba::GetVWall(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[6]);
	else
		return -1;	
}

int Roomba::GetSideBrushOC(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[7] & B00000001);
	else
		return -1;	
}

int Roomba::GetVacuumOC(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[7] & B00000010);
	else
		return -1;	
}

int Roomba::GetMainBrushOC(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[7] & B00000100);
	else
		return -1;	
}

int Roomba::GetRMotorOC(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(sensorData[7] & B00001000);
	else
		return -1;	
}

int Roomba::GetLMotorOC(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return(bool(sensorData[7] & B00010000));
	else
		return -1;	
}

int Roomba::GetLDirt(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return((byte)sensorData[8]);
	else
		return -1;	
}

int Roomba::GetRDirt(){
	// using package 1, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 1);
	
	if(dataBytes == 10)
		return((byte)sensorData[9]);
	else
		return -1;	
}

// 2nd package

int Roomba::GetRemoteControl(){
	// using package 1, 10 bytes
	byte sensorData[6];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 2);
	
	if(dataBytes == 6)
		return((byte)sensorData[0]);
	else
		return -1;
}

int Roomba::GetMaxButton(){
	// using package 1, 10 bytes
	byte sensorData[6];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 2);
	
	if(dataBytes == 6)
		return((bool)(sensorData[1] & B00000001));
	else
		return -1;
}

int Roomba::GetCleanButton(){
	// using package 1, 10 bytes
	byte sensorData[6];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 2);
	
	if(dataBytes == 6)
		return((bool)(sensorData[1] & B00000010));
	else
		return -1;
}

int Roomba::GetSpotButton(){
	// using package 1, 10 bytes
	byte sensorData[6];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 2);
	
	if(dataBytes == 6)
		return((bool)(sensorData[1] & B00000100));
	else
		return -1;
}

int Roomba::GetPowerButton(){
	// using package 1, 10 bytes
	byte sensorData[6];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 2);
	
	if(dataBytes == 6)
		return((bool)(sensorData[1] & B00001000));
	else
		return -1;
}

int Roomba::GetDistance(){
	// using package 1, 10 bytes
	byte sensorData[6];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 2);
	
	if(dataBytes == 6)
		return((int)word(sensorData[2], sensorData[3]));
	else
		return -1;
}

int Roomba::GetAngle(){
	// using package 1, 10 bytes
	byte sensorData[6];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 2);
	
	if(dataBytes == 6)
		return((int)word(sensorData[4], sensorData[5]));
	else
		return -1;
}

// 3rd package
int Roomba::GetBatteryChargingState(){
	// using package 3, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 3);
	
	if(dataBytes == 10)
		return((int)sensorData[0]);
	else
		return -1;	
}

unsigned int Roomba::GetBatteryMilliVolts(){
	// using package 3, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 3);
	
	if(dataBytes == 10)
		return(word(sensorData[1], sensorData[2]));
	else
		return -1;	
}

int Roomba::GetBatteryMilliAmps(){
	// using package 3, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 3);
	
	if(dataBytes == 10)
		return((int)word(sensorData[3], sensorData[4]));
	else
		return -1;	
}

int Roomba::GetBatteryTemperature(){
	// using package 3, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 3);
	
	if(dataBytes == 10)
		return((int)sensorData[5]);
	else
		return -1;	
}

unsigned int Roomba::GetBatteryCharge(){
	// using package 3, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 3);
	
	if(dataBytes == 10)
		return(word(sensorData[6], sensorData[7]));
	else
		return -1;	
}

unsigned int Roomba::GetBatteryCapacity(){
	// using package 3, 10 bytes
	byte sensorData[10];
	int dataBytes = 0;
	dataBytes = PollSensors(sensorData, 3);
	
	if(dataBytes == 10)
		return(word(sensorData[8], sensorData[9]));
	else
		return -1;	
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
  LEDByte1 = (LEDByte1 & B11001111);
  UpdateLEDs();
}

void Roomba::SetSLEDGreen(){
  LEDByte1 = (LEDByte1 & B11001111);
  LEDByte1 = (LEDByte1 | B00100000);
  UpdateLEDs();
}

void Roomba::SetSLEDRed(){
  LEDByte1 = (LEDByte1 & B11001111);
  LEDByte1 = (LEDByte1 | B00010000);
  UpdateLEDs();
}

void Roomba::SetSLEDAmber(){
  LEDByte1 = (LEDByte1 | B00110000);
  UpdateLEDs();
}

void Roomba::DemoSLED(int delayLength){
  // cycle through the colors
  SetSLEDOff();
  delay(delayLength);
  SetSLEDGreen();
  delay(delayLength);
  SetSLEDRed();
  delay(delayLength);
  SetSLEDAmber();  
  delay(delayLength);
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


void Roomba::MainBrushOn(){
	MotorByte = (MotorByte | B00000100);
	
	mySerial.write(138);
	delay(10);
	mySerial.write(MotorByte);
}
void Roomba::MainBrushOff(){
	MotorByte = (MotorByte & B00000011);
	
	mySerial.write(138);
	delay(10);
	mySerial.write(MotorByte);
}
void Roomba::VacuumOn(){
	MotorByte = (MotorByte | B00000010);
	
	mySerial.write(138);
	delay(10);
	mySerial.write(MotorByte);
}
void Roomba::VacuumOff(){
	MotorByte = (MotorByte & B00000101);
	
	mySerial.write(138);
	delay(10);
	mySerial.write(MotorByte);
}
void Roomba::SideBrushOn(){
	MotorByte = (MotorByte | B00000001);
	
	mySerial.write(138);
	delay(10);
	mySerial.write(MotorByte);
}
void Roomba::SideBrushOff(){
	MotorByte = (MotorByte & B00000110);
	
	mySerial.write(138);
	delay(10);
	mySerial.write(MotorByte);
}

void Roomba::DemoMotors(int delayTime){
  MainBrushOn();
  delay(delayTime);
  MainBrushOff();
  delay(delayTime);
  SideBrushOn();
  delay(delayTime);
  SideBrushOff();
  delay(delayTime);
  VacuumOn();
  delay(delayTime);
  VacuumOff();
}

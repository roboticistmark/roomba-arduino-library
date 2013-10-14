#include <Roomba.h>
#include <SoftwareSerial.h>

const int deviceDetectPin = 2;

const int txPin = 11;
const int rxPin = 10;
const int baudRateRoomba = 57600;
const int baudRatePC = 115200;


Roomba myRoomba(10, 11, baudRateRoomba);

byte LEDByteS = 0;

void setup() {
  // initialize serial:
  Serial.begin(115200);
  Serial.print("Starting program");
    
/*  pinMode(deviceDetectPin, OUTPUT);

  // pulse the device detect pin to enable the roomba
  //  this code is suspect... better to tie the DD to gnd with a resistor
  digitalWrite(deviceDetectPin, HIGH);
  delay(1000);  
  digitalWrite(deviceDetectPin, LOW);
  delay(1000);
  digitalWrite(deviceDetectPin, HIGH);  
  */
  
  // 3 commands to put the roomba into safe mode:
  myRoomba.Start();
  myRoomba.Command();
  myRoomba.Safe();
}

void loop() {
  
  myRoomba.DemoPLED(10);
  myRoomba.DemoSLED(1000);  
  myRoomba.DemoMotors(1000);
  
  while(1){
  }
}




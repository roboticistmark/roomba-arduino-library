#include <Roomba.h>
#include <SoftwareSerial.h>

void DemoSensorSet3();

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
  Serial.println("Starting program");

 /* pinMode(deviceDetectPin, OUTPUT);

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
  //myRoomba.Command();
  //myRoomba.Safe();
}

void loop() {
 
  // demo that roomba is in the right mode
  myRoomba.DemoSLED(300);
  DemoSensorSet3();
  
  //myRoomba.DemoPLED(10);    
  //myRoomba.DemoMotors(1000);
  
  while(1){
  }
}

void DemoSensorSet3(){
  Serial.print("Charging state: ");
  Serial.println(myRoomba.GetBatteryChargingState());
  
  Serial.print("Battery voltage: ");
  Serial.print(myRoomba.GetBatteryMilliVolts());
  Serial.println(" mV");
  
  Serial.print("Battery current: ");
  Serial.print(myRoomba.GetBatteryMilliAmps());
  Serial.println(" mA");
  
  Serial.print("Battery temperature: ");
  Serial.print(myRoomba.GetBatteryTemperature());
  Serial.println(" C");
  
  Serial.print("Battery charge: ");
  Serial.print(myRoomba.GetBatteryCharge());
  Serial.println(" mAh");
  
  Serial.print("Battery capacity: ");
  Serial.print(myRoomba.GetBatteryCapacity());
  Serial.println(" mAh");
  
}




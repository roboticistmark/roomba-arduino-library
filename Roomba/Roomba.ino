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
  DemoSensorSet1();
  DemoSensorSet2();
  DemoSensorSet3();

  
  //myRoomba.DemoPLED(10);    
  //myRoomba.DemoMotors(1000);
  
  while(1){
  }
}

void DemoSensorSet1(){
  Serial.print("Right bump: ");
  Serial.println(myRoomba.GetRBump());
  
  Serial.print("Left bump: ");
  Serial.println(myRoomba.GetLBump());
  
  Serial.print("Right wheel drop: ");
  Serial.println(myRoomba.GetRWheelDrop());
  
  Serial.print("Center wheel drop: ");
  Serial.println(myRoomba.GetCWheelDrop());
  
  Serial.print("Left wheel drop: ");
  Serial.println(myRoomba.GetLWheelDrop());

  Serial.print("Wall: ");
  Serial.println(myRoomba.GetWall());
  
  Serial.print("Left cliff: ");
  Serial.println(myRoomba.GetLCliff());

  Serial.print("Front left cliff: ");
  Serial.println(myRoomba.GetFLCliff());

  Serial.print("Front right cliff: ");
  Serial.println(myRoomba.GetFRCliff());

  Serial.print("Right cliff: ");
  Serial.println(myRoomba.GetRCliff());

  Serial.print("Virtual wall: ");
  Serial.println(myRoomba.GetVWall());

  Serial.print("Side brush over current: ");
  Serial.println(myRoomba.GetSideBrushOC());

  Serial.print("Vacuum over current: ");
  Serial.println(myRoomba.GetVacuumOC());
  
  Serial.print("Main brush over current: ");
  Serial.println(myRoomba.GetMainBrushOC());
  
  Serial.print("Right drive over current: ");
  Serial.println(myRoomba.GetRMotorOC());
  
  Serial.print("Left drive over current: ");
  Serial.println(myRoomba.GetLMotorOC());
  
  Serial.print("Left dirt: ");
  Serial.println(myRoomba.GetLDirt());
  
  Serial.print("Right dirt: ");
  Serial.println(myRoomba.GetRDirt());
		
}

void DemoSensorSet2(){
  Serial.print("Remote control: ");
  Serial.println(myRoomba.GetRemoteControl());
  
  Serial.print("Max button: ");
  Serial.println(myRoomba.GetMaxButton());
  
  Serial.print("Clean button: ");
  Serial.println(myRoomba.GetCleanButton());
  
  Serial.print("Spot button: ");
  Serial.println(myRoomba.GetSpotButton());

  Serial.print("Power button: ");
  Serial.println(myRoomba.GetPowerButton());
  
  Serial.print("Distance: ");
  Serial.println(myRoomba.GetDistance());
  
  Serial.print("Angle: ");
  Serial.println(myRoomba.GetAngle());


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




#include "Arduino.h"
#include "SoftwareSerial.h"

#ifndef ROOMBA_H
#define ROOMBA_H

class Roomba
{
	public:
		Roomba(int serialRX, int serialTX, int baudRateRoomba);

		// mode changing commands
		void Start();
		void Command();
		void Safe();
		void Full();
		void Power();
		
		// cleaning commands
		void Spot();
		void Clean();
		void Max();
		
		// sensor functions
		int PollSensors(byte *sensorData, byte package);
		unsigned int GetBatteryMilliVolts();
		int GetBatteryChargingState();
		int GetBatteryMilliAmps();
		int GetBatteryTemperature();
		unsigned int GetBatteryCharge();
		unsigned int GetBatteryCapacity();
		
		// LED functions
		void SetPLEDIntensity(byte intensity);
		void SetPLEDColor(byte color);
		void SetSLEDOff();
		void SetSLEDGreen();
		void SetSLEDRed();
		void SetSLEDAmber();
		void DemoPLED(int stepsize);
		void DemoSLED(int delayLength);
		
		
		// motor functions
		void MainBrushOn();
		void MainBrushOff();
		void VacuumOn();
		void VacuumOff();
		void SideBrushOn();
		void SideBrushOff();
		void DemoMotors(int delayTime);
		
	private:
		void UpdateLEDs(); // low level LED update function
		
		// LED status bytes
		byte LEDByte1;
		byte LEDByte2;
		byte LEDByte3;
		
		// motor bytes
		byte MotorByte;
		
		SoftwareSerial mySerial; // driver to communicate with the serial port
};



#endif

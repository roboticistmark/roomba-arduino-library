#include "Arduino.h"

#ifndef ROOMBA_H
#define ROOMBA_H

class Roomba
{
	public:
		Roomba();
		void SetPLEDIntensity(byte intensity);
		void SetPLEDColor(byte color);
		void SetSLEDOff();
		void SetSLEDGreen();
		void SetSLEDRed();
		void SetSLEDAmber();
		void DemoPLED(int stepsize);
	private:
		void UpdateLEDs();
		byte LEDByte1;
		byte LEDByte2;
		byte LEDByte3;
};



#endif

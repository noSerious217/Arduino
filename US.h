#ifndef US_h
#define US_h

#include "Arduino.h"

class US
{
  private:
	long duration = 0;
	int Trig_pin;
	int Echo_pin;
	void Timing();
	
  public:
	void init(int t, int e);
	long distance();	
};

#endif
#ifndef Vehicle_h
#define Vehicle_h

#include "Arduino.h"
#include "Engine.h"

class Vehicle
{
	private:
	Engine FLE;
	Engine FRE;
	Engine BLE;
	Engine BRE;
	int stby1;
	int stby2;
	boolean busy;
	
	public:
	void init(int s1, int s2);
	void forward();
	void backward();
	void halt();
	void clock();
	void againstclock();
	void stop();
	bool isBusy();
};

#endif
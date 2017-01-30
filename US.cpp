#include "Arduino.h"
#include "US.h"

void US::Timing()
{
	digitalWrite(Trig_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(Trig_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(Trig_pin, LOW);
	duration = pulseIn(Echo_pin, HIGH);
}

void US::init(int t,int e)
{
    Trig_pin=t;
    Echo_pin=e;
    pinMode(t,OUTPUT);
    pinMode(e,INPUT);
}

long US::distance()
{       
	Timing();
    return  duration /29 / 2 ;
}
#include "Arduino.h"
#include "Engine.h"

void Engine::initialize(int x, int y, int z)
{
	a1=x;
    a2=y;
    a3=z;
    pinMode(a1,OUTPUT);
    pinMode(a2,OUTPUT);
    pinMode(a3,OUTPUT);
    analogWrite(a3,250);
    on[0]=false;
    on[1]=false;
    Serial.println(a2);
}

void Engine::forward()
{
	on[0]=true;
    on[1]=false;
    digitalWrite(a1,HIGH);
    digitalWrite(a2,LOW);
}

void Engine::backward()
{
    on[0]=false;
    on[1]=true;
    digitalWrite(a1,LOW);
    digitalWrite(a2,HIGH); 
}

void Engine::reverse()
{
    if (on[0])
    {
		on[0]=false;
		digitalWrite(a1,LOW);
    }
    else
    {
		on[0]=true;
		digitalWrite(a1,HIGH);
    }
    if (on[1])
    {
		on[1]=false;
		digitalWrite(a2,LOW);
    }
    else
    {
		on[1]=true;
		digitalWrite(a2,HIGH);
	}
}  

void Engine::stop()
{
    on[0]=false;
    on[1]=false;
    digitalWrite(a1,LOW);
    digitalWrite(a2,LOW);
} 
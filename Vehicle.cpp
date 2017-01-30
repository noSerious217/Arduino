#include "Arduino.h"
#include "Engine.h"
#include "Vehicle.h"

void Vehicle::init(int s1, int s2)
{
    FLE.initialize(22,23,2);
    FRE.initialize(28,27,4);
    BLE.initialize(26,25,3);
    BRE.initialize(30,31,5);
    stby1 = s1;
    pinMode(stby1,OUTPUT);
    digitalWrite(stby1,HIGH);
    stby2 = s2;
    pinMode(stby2,OUTPUT);
    digitalWrite(stby2,HIGH);
}

void Vehicle::forward()
{
    busy=true;
    FLE.forward();
    FRE.forward();
    BLE.forward();
    BRE.forward();
    busy=false;
}

void Vehicle::backward()
{
    busy=true;
    FLE.backward();
    FRE.backward();
    BLE.backward();
    BRE.backward();
    busy=false;
}

void Vehicle::halt()
{
    busy=true;
    FLE.reverse();
    FRE.reverse();
    BLE.reverse();
    BRE.reverse();
    delay(5);
    FLE.stop();
    FRE.stop();
    BLE.stop();
    BRE.stop();
    busy=false;
}

void Vehicle::clock()
{
    busy=true;
    FLE.forward();
    BLE.forward();
    FRE.backward();
    BRE.backward();
    busy=false;
}

void Vehicle::againstclock()
{
    busy=true;
    FLE.backward();
    BLE.backward();
    FRE.forward();
    BRE.forward();
    busy=false;
}

void Vehicle::stop()
{
    busy=true;
    FLE.stop();
    FRE.stop();
    BRE.stop();
    BLE.stop();
    busy=false;
}

bool Vehicle::isBusy()
{
    return busy;
}
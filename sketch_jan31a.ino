#include <Scanner.h>

Scanner FLS;
Scanner FRS;
Scanner BLS;
Scanner BRS;

void setup() {
  FLS.init(2,A0);//Trigger - 2, Echo - A0
  FRS.init(3,A1);//Trigger - 3, Echo - A1
  BLS.init(4,A2);//Trigger - 4, Echo - A2
  BRS.init(5,A3);//Trigger - 5, Echo - A3
}

void clear()
{
  if (!FLS.alarm())
  {
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
  }
  if (!BRS.alarm())
  {
    digitalWrite(9,LOW);
    digitalWrite(13,LOW);
  }
  if (!FRS.alarm())
  {
    digitalWrite(7,LOW);
  }
  if(!BLS.alarm())
  {
    digitalWrite(8,LOW);
  }
}

void loop() 
{
  if (FLS.alarm())
  {
    if (FRS.alarm())
    {
      digitalWrite(10,HIGH);
    }
    else digitalWrite(6,HIGH);
  }
  else if (BRS.alarm())
  {
    if (BLS.alarm())
    {
      digitalWrite(13,HIGH);
    }
    else digitalWrite(9,HIGH);
  }
  else if (FRS.alarm())
  {
    digitalWrite(7,HIGH);
  }
  else if (BLS.alarm())
  {
    digitalWrite(8,HIGH);
  }  
  clear();
}

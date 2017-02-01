#include <Vehicle.h>

Vehicle vh;

void setup() {
  vh.init(24,29);
  attachInterrupt(0,interrupt0,RISING);
  attachInterrupt(1,interrupt1,RISING);
  attachInterrupt(2,interrupt2,RISING);
  attachInterrupt(3,interrupt3,RISING);
  attachInterrupt(4,interrupt4,RISING);
  attachInterrupt(5,interrupt5,RISING);
}

void interrupt0()
{
  vh.backward();
  delay(10);
  vh.stop();
}

void interrupt1()
{
  vh.forward();
  delay(10);
  vh.stop();
}

void interrupt2()
{
  vh.againstclock();
  delay(100);
  interrupt0();
}

void interrupt3()
{
  vh.clock();
  delay(100);
  interrupt(0);
}

void interrupt4()
{
  vh.clock();
  delay(100);
  interrupt1();
}

void interrupt5()
{
  vh.againstclock();
  delay(100);
  interrupt1();
}

void loop() {
  
 }


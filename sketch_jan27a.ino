#include <Scanner.h>

#include <Vehicle.h>

Vehicle vh;
US detector;

void setup() {
  Serial.begin(9600);
  vh.init(24,29);
  detector.init(33,32);  
  vh.backward();
}

void loop() {
  if (detector.distance()<15) 
  {
    vh.halt();
    delay(10);
    vh.clock();
    delay(800);
    vh.stop();
    delay(10);
  }
  else
  {
    vh.backward();
    delay(10);
    vh.stop();  
    delay(1);
  }
 }


#include "Arduino.h"
#include "Scanner.h"

void Scanner::init(US s)
{
	scanner=s;
}

bool Scanner::alarm()
{
	return scanner.distance()>10;
}
#include "Arduino.h"
#include "Scanner.h"

void Scanner::init(US s)
{
	scanner=s;
}

void Scanner::init(int t, int e)
{
	scanner.init(t,e);
}

bool Scanner::alarm()
{
	return scanner.distance()>10;
}
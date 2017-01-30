#ifndef Scanner_h
#define Scanner_h

#include "Arduino.h"
#include "US.h"

class Scanner
{
	private:
	US scanner;
	
	public:
	
	void init(US s);
	bool alarm();
};
#endif
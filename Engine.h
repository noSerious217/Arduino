#ifndef Engine_h
#define	Engine_h

#include "Arduino.h"

class Engine
{
	private:
	int	a1=0;
	int	a2=0;
	int a3=0;
	int speed;
	boolean on[2];
	
	public:
	void initialize(int x, int y, int z);
	void forward();
	void backward();
	void reverse();
	void stop();
};

#endif


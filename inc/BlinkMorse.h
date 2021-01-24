


#ifndef BLINKMORSE_H
#define BLINKMORSE_H

#include "BeepMorse.h"
#include <windows.h>
#define _WIN32_WINNT 0x500
class BlinkMorse :public BeepMorse {

public:
	BlinkMorse(int dot_time,
		int dash_time, int pause_time) :BeepMorse(dot_time,dash_time,pause_time) {};
	BlinkMorse() :BeepMorse() {};
	virtual void emmit(MorseCode) override;




};


#endif // !BLINKMORSE_H

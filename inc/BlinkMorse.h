


#ifndef BLINKMORSE_H
#define BLINKMORSE_H

#include "BeepMorse.h"
#include <windows.h>
#define _WIN32_WINNT 0x500
class BlinkMorse :public IMorse {

public:
	
	BlinkMorse();
	BlinkMorse(int,int,int);

	//BlinkMorse(const BlinkMorse&);  // nie ma potrzeby deklarowaæ kontruktora kopiujacego 
	//BlinkMorse& operator=(const BlinkMorse&);// ani operatora = ,zostana one wygenerowane automatycznie

	void setDotTime(int);
	void setdashTime(int);
	void setPauseTime(int);

	virtual void emmit(MorseCode) override;
	virtual BlinkMorse* clone() { return new BlinkMorse(*this); }
protected:
	int dot_time = 500;
	int dash_time = 500;
	int pause_time = 500;


};


#endif // !BLINKMORSE_H

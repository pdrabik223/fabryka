
//autor Piotr Drabik
// data utworzenia pliku : 22.01.2021
//
// BlinkMorse wyswietla wiadomosc morsem za pomoca klawisza numLock
// !wymogiem jest system posiadanie systemu windows 
// 
//
//historia zmian:
//data:										autor:											opis:
//
//
//
//
#pragma once
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

	int setDotTime();
	int setdashTime();
	int setPauseTime();



	virtual void emmit(MorseCode) override; // wyswietla kod morsa za pomoca diody numlock
	virtual BlinkMorse* clone() { return new BlinkMorse(*this); } // na potrzeby factory
	virtual ~BlinkMorse() {};
protected:
	int dot_time;
	int dash_time ;
	int pause_time ;


};


#endif // !BLINKMORSE_H

//autor Piotr Drabik
// data utworzenia pliku : 22.1.2021
//
// klasa factory dla narzedzia morse 
// pozwala na kozystanie z wybranej klasy nalezacej do rodziny morse 
// bez wgladu w strukore rodziny  
//
//
//historia zmian:
//data:										autor:											opis:
//
//
//
//
#pragma once
#ifndef FACTORY_H
#define FACTORY_H
#include "BeepMorse.h"
#include "BlinkMorse.h"
#include "ConsoleMorse.h" 
#include "FileMorse.h"
#include <vector>
#include <string>
#include <map>
class factory {
	

public:
	static enum output {
		Beep,
		Blink,
		Console,
		File
	};

	factory();
	factory(const factory&); // ta klasa wymaga zarowno konstruktora kopiujacego 
	factory& operator=(const factory& other);// jak i operatora =
	

	void setExternalInfo(); // ustawia wartosci na defaultowe  
	void setExternalInfo(std::string); // pobiera dane potrzebne do emitowania wiadomosci
	void setOutput(output);// ustala sposob emitowania wiadomosci
	void emmit(MorseCode); // "emituje" wiadomosc, 
	

	void set_filepath(std::string);

	void set_dot_freaquency(int);
	void set_dash_freaquency(int);
	void set_dot_time(int);
	void set_dash_time(int);
	void set_pause_time(int);

	std::string getFilePath();
	int getDashFreaquency();
	int getDotTime();
	int getdashTime();
	int getPauseTime();
	int getDotFreaquency();

	~factory() { delete morse;  }; // morse w zadnym momencie nie jest nullptr
								// dlatego nie musze sprawdzac czy jest


protected:


	std::string file_path;

	int dot_freaquency;
	int dash_freaquency;
	int dot_time;
	int dash_time;
	int pause_time;
	
	IMorse* morse; // 

};


#endif // !FACTORY_H



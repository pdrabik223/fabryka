
//autor Piotr Drabik
// data utworzenia pliku : 22.01.2021
//
//	FileMorse  zapisuje wiadomosc do pliku 
//  zapisywana wiadomosc jest w z gory ustalonym standardzie 
//
//
/*

MP  // naglowek z rozszerzeniem
dot_freaquency	1800 // zmienne z zadeklarownymi wartosciami
dash_freaquency	800
dot_time	300
dash_time	500
pause_time 	600
----- ...----...----- ..--. ..-  // widomosc zapisana w morsie
// format nie pozwala na komentarze


*/

//historia zmian:
//data:										autor:											opis:
//
//
//
//
#pragma once 
#ifndef FILEMORSE_H
#define FILEMORSE_H

#include "IMorse.h"
#include <fstream>



class FileMorse : public IMorse {
public:


	FileMorse(std::string); // konstruktor w miejsce niepodanych wartosci wpisze default


	FileMorse(std::string, int, int, int,
		int, int);

	//	FileMorse(const FileMorse&); nie ma potrzeby deklarowac konstruktora kopiujacego dla tej klasy, kompilator zrobi to za nas
	//	FileMorse& operator=(const FileMorse&); podobnie z operatorem=  

	virtual void emmit(MorseCode) override; // zapisz dane i wiadomosc do pliku 
	virtual FileMorse* clone() { return new FileMorse(*this); } // na potrzeby factory
	virtual ~FileMorse() {};// teoretycznie destruktor nie jest wymagany 

	void setfilepath(std::string);

	void setAll(int, int, int, int, int);
	void setDotFreaquency(int);
	void setDashFreaquency(int);
	void setDotTime(int);
	void setdashTime(int);
	void setPauseTime(int);


	int getDotFreaquency();
	int getDashFreaquency();
	int getDotTime();
	int getdashTime();
	int getPauseTime();
	std::string getFilePath();

private:
	std::string file_path;
	// by zapis do pliku zapisywal wszystkie dane klasa musi posiadac informacje o nich 
	int dot_freaquency;
	int dash_freaquency;
	int dot_time;
	int dash_time;
	int pause_time;
};

#endif // FILEMORSE_H
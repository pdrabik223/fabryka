//autor Piotr Drabik
// data utworzenia pliku : 22.01.2021
//
// pozwala na wyswietlanie podanej wiadomosci w konsoli
//
//
//historia zmian:
//data:										autor:											opis:
//
//
//
//
#pragma once
#ifndef CONSOLEMORSE_H
#define CONSOLEMORSE_H
#include "IMorse.h"


class ConsoleMorse : public IMorse {
public:
	ConsoleMorse(){};
	// poniewaz klasa nie posiada zadnych wartoœci 
	// nie potrzebje deklarowac zni kontruktora kopiujacego ani operatora=
	// ani destruktora



  virtual void emmit(MorseCode) override; // wyswietla wiadomosc 
  virtual ConsoleMorse* clone() { return new ConsoleMorse(*this); } // na potrzeby konstruktora kopiujacego w factory
};
#endif // CONSOLEMORSE_H
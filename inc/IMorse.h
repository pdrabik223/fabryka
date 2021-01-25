//autor Piotr Drabik
// data utworzenia pliku : 22.01.2021
//
// klasa bazowa "rodzic" dla rodziny morse 
// nie jest mozliwe stworzenie obiektu IMorse
// wszystkie funkcje ma wirtualne
//
//historia zmian:
//data:										autor:											opis:
//
//
//
//
#pragma once 
#ifndef IMORSE_H
#define IMORSE_H
#include "MorseCode.h"
#include <iostream>
class IMorse {
public:
  virtual void emmit(MorseCode) = 0; // wyswietl 
  virtual ~IMorse() {}; // destruktor
  virtual IMorse* clone() = 0; // clone na potrzeby factory
protected:
	IMorse() {};

  // IMorse(const IMorse&); IMorse jest Interfejsem,
  // wiec nie mozna stwozyc jego obiektu
};

#endif // IMORSE_H

//autor Piotr Drabik
// data utworzenia pliku : 22.01.2021
//
// 
// MorseCode klasa konwertujaca litery, znaki , cyfry alfabetu na kod morsa
// 
//
//historia zmian:
//data:										autor:											opis:
//
//
//
//
#pragma once 
#ifndef MORSECODE_H
#define MORSECODE_H

#include <string>

class MorseCode {

  MorseCode() = delete; // nie moze istniec kod morsa bez translacji 

public:
  MorseCode(const char *); 
  MorseCode(char);
  MorseCode(int);
  MorseCode(double);

  char operator[](unsigned position); // to jest lepiej zrobic iteratorem

  unsigned size() { return parsed_code.size();} 

  MorseCode(const MorseCode &); 
  MorseCode &operator=(const MorseCode &);
  
  
  std::string parse(char); // funkcja wykonujaca prace 

private:
  std::string parsed_code;
};

#endif // MORSECODE_H

#ifndef IMORSE_H
#define IMORSE_H
#include "MorseCode.h"
#include <iostream>
class IMorse {
public:
  virtual void emmit(MorseCode) = 0;

protected:
  IMorse() {}
  // IMorse(const IMorse&); IMorse jest Interfejsem,
  // wiec nie mozna stwozyc jego obiektu
};

#endif // IMORSE_H
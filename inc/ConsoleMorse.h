#ifndef CONSOLEMORSE_H
#define CONSOLEMORSE_H
#include "IMorse.h"


class ConsoleMorse : public IMorse {
public:
	ConsoleMorse(){};
	// poniewaz klasa nie posiada zadnych wartoœci 
	// nie potrzebje deklarowac zni kontruktora kopiujacego ani operatora=
	// ani destruktora



  virtual void emmit(MorseCode) override;
  virtual ConsoleMorse* clone() { return new ConsoleMorse(*this); }
};
#endif // CONSOLEMORSE_H
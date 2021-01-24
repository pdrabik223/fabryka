#ifndef CONSOLEMORSE_H
#define CONSOLEMORSE_H
#include "BeepMorse.h"
#include "MorseCode.h"

class ConsoleMorse : public BeepMorse {
public:
  ConsoleMorse() : BeepMorse(){};
	ConsoleMorse(int dot_freaquency, int dash_freaquency, int dot_time,
	  int dash_time, int pause_time) :BeepMorse(dot_freaquency, dash_freaquency, dot_time, dash_time, pause_time) {};



  ConsoleMorse(const ConsoleMorse& other) : BeepMorse(other) {};


  ConsoleMorse &operator=(const ConsoleMorse & other );

 

  virtual void emmit(MorseCode) override;
};
#endif // CONSOLEMORSE_H
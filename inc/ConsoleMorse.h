#ifndef CONSOLEMORSE_H
#define CONSOLEMORSE_H
#include "BeepMorse.h"
#include "MorseCode.h"

class ConsoleMorse : public BeepMorse {
public:
  ConsoleMorse() : BeepMorse(){};

  ConsoleMorse(const ConsoleMorse &);
  ConsoleMorse &operator=(const ConsoleMorse &);

  virtual void emmit(MorseCode) override;
};
#endif // CONSOLEMORSE_H
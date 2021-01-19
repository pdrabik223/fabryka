#include "BeepMorse.h"

#ifndef FILEMORSE_H
#define FILEMORSE_H

class FileMorse : public BeepMorse {
public:
  virtual void emmit(MorseCode) override;

private:
  std::string filepath;
};

#endif // FILEMORSE_H
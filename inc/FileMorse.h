#include "BeepMorse.h"

#ifndef FILEMORSE_H
#define FILEMORSE_H


#include <fstream>



class FileMorse : public BeepMorse {
public:


	FileMorse(std::string);

  virtual void emmit(MorseCode) override;
  void setfilepath(std::string);

private:
  std::string filepath;
};

#endif // FILEMORSE_H
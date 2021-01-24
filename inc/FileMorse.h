#include "BeepMorse.h"

#ifndef FILEMORSE_H
#define FILEMORSE_H


#include <fstream>



class FileMorse : public BeepMorse {
public:


	FileMorse(std::string);
	FileMorse(std::string path, int dot_freaquency, int dash_freaquency, int dot_time,
		int dash_time, int pause_time);
	FileMorse(const FileMorse&);
	FileMorse& operator=(const FileMorse&);

  virtual void emmit(MorseCode) override;
  void setfilepath(std::string);

private:
  std::string filepath;
};

#endif // FILEMORSE_H
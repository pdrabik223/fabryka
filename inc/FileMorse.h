

#ifndef FILEMORSE_H
#define FILEMORSE_H

#include "IMorse.h"
#include <fstream>



class FileMorse : public IMorse {
public:


	FileMorse(std::string);
	

	FileMorse(std::string path, int dot_freaquency, int dash_freaquency, int dot_time,
		int dash_time, int pause_time);

//	FileMorse(const FileMorse&); nie ma potrzeby deklarowac konstruktora kopiujacego dla tej klasy, kompilator zrobi to za nas
//	FileMorse& operator=(const FileMorse&); podobnie z operatorem=  

  virtual void emmit(MorseCode) override;
  virtual FileMorse* clone() { return new FileMorse(*this); }
  void setfilepath(std::string);

  void setAll(int, int, int, int, int);
  void setDotFreaquency(int);
  void setDashFreaquency(int);

  void setDotTime(int);
  void setdashTime(int);
  void setPauseTime(int);

private:
  std::string filepath;

  int dot_freaquency;
  int dash_freaquency;
  int dot_time;
  int dash_time;
  int pause_time;
};

#endif // FILEMORSE_H
//autor Piotr Drabik
// data utworzenia pliku : 22.01.2021
//
// poszwal odgrywac waidaomosc za pomoca glosnikow systemowych 
// wymagana jest platworma windows
//
//historia zmian:
//data:										autor:											opis:
//
//
//
//


#pragma once 
#ifndef BEEPMORSE_H
#define BEEPMORSE_H
#include "IMorse.h"
#include "MorseCode.h"

#include <windows.h>

class BeepMorse : public IMorse {

public:
  BeepMorse(); 
 
  BeepMorse(int, int, int, int, int);
 
  //BeepMorse(const BeepMorse &); // konstruktor kopiujacy jest trywialny
  //BeepMorse &operator=(const BeepMorse &); // wraz operatorem = zostanie wygenerowany automattycznie 

  void setAll(int, int, int, int, int);
  void setDotFreaquency(int);
  void setDashFreaquency(int);

  void setDotTime(int);
  void setdashTime(int);
  void setPauseTime(int);

  
  int getDotFreaquency();
  int getDashFreaquency();
  int getDotTime();
  int getdashTime();
  int getPauseTime();





  virtual void emmit(MorseCode) override;
  virtual BeepMorse* clone() { return new BeepMorse(*this); } // na potrzeby factory
  virtual ~BeepMorse() {};

protected:
 

  int dot_freaquency;
  int dash_freaquency;
  int dot_time;
  int dash_time;
  int pause_time;
};
#endif // BEEPMORSE_H

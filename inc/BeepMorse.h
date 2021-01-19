#ifndef BEEPMORSE_H
#define BEEPMORSE_H
#include "IMorse.h"
#include "MorseCode.h"

class BeepMorse : public IMorse {

public:
  BeepMorse();
  BeepMorse(int, int, int, int, int);

  BeepMorse(const BeepMorse &);
  BeepMorse &operator=(const BeepMorse &);

  void setAll(int, int, int, int, int);
  void setDotFreaquency(int);
  void setDashFreaquency(int);

  void setDotTime(int);
  void setdashTime(int);
  void setPauseTime(int);

  virtual void emmit(MorseCode) override;

protected:
  void beep(char);

  int dot_freaquency;
  int dash_freaquency;
  int dot_time;
  int dash_time;
  int pause_time;
};
#endif // BEEPMORSE_H

#include "BeepMorse.h"

BeepMorse::BeepMorse() {
  dot_freaquency = 100;
  dash_freaquency = 200;
  dot_time = 1000;
  dash_time = 1000;
  pause_time = 1000;
}
BeepMorse::BeepMorse(int dot_freaquency, int dash_freaquency, int dot_time,
                     int dash_time, int pause_time) {
  this->dot_freaquency = dot_freaquency;
  this->dash_freaquency = dash_freaquency;
  this->dot_time = dot_time;
  this->dash_time = dash_time;
  this->pause_time = pause_time;
}
BeepMorse::BeepMorse(const BeepMorse &other) {

  dot_freaquency = other.dot_freaquency;
  dash_freaquency = other.dash_freaquency;
  dot_time = other.dot_time;
  dash_time = other.dash_time;
  pause_time = other.pause_time;
}

BeepMorse &BeepMorse::operator=(const BeepMorse &other) {

  if (this == &other)
    return *this;
  dot_freaquency = other.dot_freaquency;
  dash_freaquency = other.dash_freaquency;
  dot_time = other.dot_time;
  dash_time = other.dash_time;
  pause_time = other.pause_time;

  return *this;
}

void BeepMorse::setAll(int dot_freaquency, int dash_freaquency, int dot_time,
    int dash_time, int pause_time) {
    this->dot_freaquency = dot_freaquency;
    this->dash_freaquency = dash_freaquency;
    this->dot_time = dot_time;
    this->dash_time = dash_time;
    this->pause_time = pause_time;
}

void BeepMorse::setDotFreaquency(int dot_freaquency) {
  this->dot_freaquency = dot_freaquency;
}
void BeepMorse::setDashFreaquency(int dash_freaquency) {
  this->dash_freaquency = dash_freaquency;
}
void BeepMorse::setdashTime(int dash_time) { this->dash_time = dash_time; }
void BeepMorse::setDotTime(int dot_time) { this->dot_time = dot_time; }
void BeepMorse::setPauseTime(int pause_time) { this->pause_time = pause_time; }

void BeepMorse::setDotFreaquency(int dot_freaquency) {
    this->dot_freaquency = dot_freaquency;
}
void BeepMorse::setDashFreaquency(int dash_freaquency) {
    this->dash_freaquency = dash_freaquency;
}
void BeepMorse::setdashTime(int dash_time) { this->dash_time = dash_time; }
void BeepMorse::setDotTime(int dot_time) { this->dot_time = dot_time; }
void BeepMorse::setPauseTime(int pause_time) { this->pause_time = pause_time; }



void BeepMorse::emmit(MorseCode message) {
  for (auto letter = 0; letter < message.size(); letter++) {
    switch (letter) {
    case '.':
      // beepowanie
        Beep(dot_freaquency, dot_time);
            break;
    case '-':
      // beepowanie
        Beep(dash_freaquency, dash_time);
            break;
    default:
        // beep space
        Sleep(pause_time);
        break;
    }
  }
}
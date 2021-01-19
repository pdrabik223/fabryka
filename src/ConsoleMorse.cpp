
#include "ConsoleMorse.h"

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

void ConsoleMorse::emmit(MorseCode message) {

  for (int letter = 0; letter < message.size(); letter++) {
    std::cout << message[letter];
  }
}

#include "BeepMorse.h"
#include "ConsoleMorse.h"
#include <iostream>

int main() {
  IMorse *f = new BeepMorse();

  f->emmit("fuck");

  return 0;
}

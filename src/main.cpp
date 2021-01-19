#include "BeepMorse.h"
#include "ConsoleMorse.h"
#include <iostream>

int main() {
  IMorse *f = new ConsoleMorse();

  f->emmit("fuck");

  return 0;
}

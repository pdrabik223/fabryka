


#ifndef MORSECODE_H
#define MORSECODE_H

#include <string>

class MorseCode {

  MorseCode() = delete;

public:
  MorseCode(const char *);
  MorseCode(char);
  MorseCode(int);
  MorseCode(double);

  char operator[](unsigned position); // to jest lepiej zrobic iteratorem

  unsigned size() { return parsed_code.size();}

  MorseCode(const MorseCode &);
  MorseCode &operator=(const MorseCode &);
  std::string parse(char);

private:
  std::string parsed_code;
};

#endif // MORSECODE_H

#include "MorseCode.h"

std::string MorseCode::parse(char letter) {

  switch (letter) {

  case ' ':
    return "  "; // 2 spacje pomiedzy słowami

  case 'a':
  case 'A':

    return ".-";

  case 'b':
  case 'B':

    return "-...";

  case 'c':
  case 'C':

    return "-.-.";

  case 'd':
  case 'D':

    return "-..";

  case 'e':
  case 'E':

    return ".";

  case 'f':
  case 'F':

    return "..-.";

  case 'g':
  case 'G':

    return "--.";

  case 'h':
  case 'H':

    return "....";

  case 'i':
  case 'I':

    return "..";

  case 'j':
  case 'J':

    return ".---";

  case 'k':
  case 'K':

    return "-.-";

  case 'l':
  case 'L':

    return ".-..";

  case 'm':
  case 'M':

    return ".-";

  case 'n':
  case 'N':

    return "-.";

  case 'o':
  case 'O':

    return "---";

  case 'p':
  case 'P':

    return ".--.";

  case 'q':
  case 'Q':

    return "--.-";

  case 'r':
  case 'R':

    return ".-.";

  case 's':
  case 'S':

    return "...";

  case 't':
  case 'T':

    return "-";

  case 'u':
  case 'U':

    return "..-";

  case 'v':
  case 'V':

    return "...-";

  case 'w':
  case 'W':

    return ".--";

  case 'x':
  case 'X':

    return "-..-";

  case 'y':
  case 'Y':

    return "-.--";

  case 'z':
  case 'Z':

    return "--..";
  case '1':
    return ".----";
  case '2':
    return "..---";
  case '3':
    return "...--";
  case '4':
    return "....-";
  case '5':
    return ".....";
  case '6':
    return "-....";
  case '7':
    return "--...";
  case '8':
    return "---..";
  case '9':
    return "----.";
  case '0':
    return "-----";
  default: // exception
    return " ";
  }
}

MorseCode::MorseCode(const char *message) {

  // parsed_code = "\0";

  for (char i : (std::string)message) {
    parsed_code += parse(i);
    parsed_code += ' '; // spacja po literze
  }
}

MorseCode::MorseCode(char message) {

  parsed_code = "\0";

  parsed_code = parse(message);
  parsed_code += ' '; // spacja po znaku
}

MorseCode::MorseCode(int message) {

  parsed_code = "\0";

  for (auto i : std::to_string(message))
    parsed_code += parse(i);
  parsed_code += ' '; // spacja po znaku
}

MorseCode::MorseCode(double message) {

  parsed_code = "\0";
  for (auto i : std::to_string(message))
    parsed_code += parse(i);
  parsed_code += ' '; // spacja po znaku
}
MorseCode::MorseCode(const MorseCode &other) {
  this->parsed_code = other.parsed_code;
}

MorseCode &MorseCode::operator=(const MorseCode &other) {
  if (this == &other)
    return *this;
  this->parsed_code = other.parsed_code;
  return *this;
}

char MorseCode::operator[](int position) { return parsed_code[position]; }
#include "factory.h"
#include <iostream>

int main() {

	factory f;
	f.setOutput(factory::Console);
	f.emmit("ala ma kota");

	f.setExternalInfo("900 1700 400 500 700 ");
	f.setOutput(factory::Blink);
	f.emmit("a kot ma ale");

	f.setExternalInfo("morse_output.txt");
	f.setOutput(factory::File);
	f.emmit("to dobrze ze sie maja");
	f.emmit(21);
	f.emmit(0.37);

	f.setExternalInfo("morse_output.txt");
	f.setOutput(factory::Beep);
	f.emmit("bo bez milosci zyce nie ma sensu");
	


	return 0;
}

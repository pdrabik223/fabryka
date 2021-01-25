

#include "factory.h"
#include <iostream>

int main() {

	factory f;
	f.setOutput(factory::Console);
	f.emmit("ala ma kota");

	f.setExternalInfo("900 1700 400");
	f.setOutput(factory::Blink);
	f.emmit("a");

	f.setExternalInfo("morse_output.txt");

	f.set_dot_freaquency(1800);
	f.set_dash_freaquency(800);
	f.set_dot_time(300);
	f.set_dash_time(500);
	f.set_pause_time(600);

	f.setOutput(factory::File);
	f.emmit("to dobrze ");
	f.emmit(21);
	f.emmit(0.37);


	f.setExternalInfo("700 800 900 600 400");
	f.setOutput(factory::Beep);
	factory g;
	g = f;
	g.emmit("bo bez ");
	


	return 0;
}

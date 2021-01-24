
#ifndef FACTORY_H
#define FACTORY_H
#include "BeepMorse.h"
#include "BlinkMorse.h"
#include "ConsoleMorse.h" 
#include "FileMorse.h"
#include <vector>
#include <string>

class factory {
	

public:
	static enum output {
		Beep,
		Blink,
		Console,
		File
	};

	factory();
	factory(const factory&);
	factory& operator=(const factory& other);
	
	void setExternalInfo(std::string);
	void setOutput(output);
	void emmit(MorseCode);
	
	~factory() { if(morse != nullptr) delete morse; };


protected:


	std::string filepath;
	int dot_freaquency;
	int dash_freaquency;
	int dot_time;
	int dash_time;
	int pause_time;
	
	IMorse* morse;

};


#endif // !FACTORY_H



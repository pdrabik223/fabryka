
#ifndef FACTORY_H
#define FACTORY_H
#include "BeepMorse.h"// 5 ints
#include "BlinkMorse.h"// times so 3 ints
#include "ConsoleMorse.h" // nothing
#include "FileMorse.h"// filepath
#include <vector>
#include <string>

class factory {
public:

	factory()=delete;
	factory(const factory&);
	factory& operator=(const factory& other);
	factory(std::string);
	
	
	void setAll(int, int, int, int, int);
	void setDotFreaquency(int);
	void setDashFreaquency(int);
	void setDotTime(int);
	void setdashTime(int);
	void setPauseTime(int);

	void emmit(MorseCode);
	~factory() { delete morse; };


protected:
	IMorse* morse;

};


#endif // !FACTORY_H



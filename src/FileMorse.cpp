#include "FileMorse.h"
#include <fstream>

FileMorse::FileMorse(std::string filepath)
{ // mo¿e wczytywanie danych z pluku? 
	this->dot_freaquency = dot_freaquency;
	this->dash_freaquency = dash_freaquency;
	this->dot_time = dot_time;
	this->dash_time = dash_time;
	this->pause_time = pause_time;
	this->filepath = filepath;
}

FileMorse::FileMorse(std::string filepath, int dot_freaquency, int dash_freaquency, int dot_time, int dash_time, int pause_time)
{
	this->dot_freaquency = dot_freaquency;
	this->dash_freaquency = dash_freaquency;
	this->dot_time = dot_time;
	this->dash_time = dash_time;
	this->pause_time = pause_time;
	this->filepath = filepath;

}




void FileMorse::setAll(int dot_freaquency, int dash_freaquency, int dot_time,
	int dash_time, int pause_time) {
	this->dot_freaquency = dot_freaquency;
	this->dash_freaquency = dash_freaquency;
	this->dot_time = dot_time;
	this->dash_time = dash_time;
	this->pause_time = pause_time;
}

void FileMorse::setDotFreaquency(int dot_freaquency) {
	this->dot_freaquency = dot_freaquency;
}
void FileMorse::setDashFreaquency(int dash_freaquency) {
	this->dash_freaquency = dash_freaquency;
}
void FileMorse::setdashTime(int dash_time) { this->dash_time = dash_time; }
void FileMorse::setDotTime(int dot_time) { this->dot_time = dot_time; }
void FileMorse::setPauseTime(int pause_time) { this->pause_time = pause_time; }



void FileMorse::emmit(MorseCode message)
{
	std::fstream plik;
	plik.open(filepath, std::ios::out);
	
	// moj wlasny encoding 
	// na wypadek czegos tam

	plik << "MP\n"; // pznaczenie encodingu  wymagane by plik zosta³ odczytany
	plik<<"dot_freaquency\t"<< dot_freaquency<<'\n';
	plik<<"dash_freaquency\t"<< dash_freaquency<<'\n';
	plik<<"dot_time\t"<< dot_time<<'\n';
	plik<<"dash_time\t"<< dash_time<<'\n';
	plik<<"pause_time \t"<< pause_time<<'\n';

	for (int letter = 0; letter < message.size(); letter++) {
	
		plik << message[letter];
	}

	plik.close();
}

void FileMorse::setfilepath(std::string filepath)
{
	this->filepath = filepath;
}

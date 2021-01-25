#include "FileMorse.h"
#include <fstream>

FileMorse::FileMorse(std::string file_path)
{ // mo¿e wczytywanie danych z pluku? 
	this->dot_freaquency = dot_freaquency;
	this->dash_freaquency = dash_freaquency;
	this->dot_time = dot_time;
	this->dash_time = dash_time;
	this->pause_time = pause_time;
	this->file_path = file_path;
}

FileMorse::FileMorse(std::string file_path, int dot_freaquency, int dash_freaquency, int dot_time, int dash_time, int pause_time)
{
	this->dot_freaquency = dot_freaquency;
	this->dash_freaquency = dash_freaquency;
	this->dot_time = dot_time;
	this->dash_time = dash_time;
	this->pause_time = pause_time;
	this->file_path = file_path;

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

int FileMorse::getDashFreaquency() { return dash_freaquency; }
int FileMorse::getDotTime() { return dot_time; }
int FileMorse::getdashTime() { return dash_time; }
int FileMorse::getPauseTime() { return pause_time; }
std::string FileMorse::getFilePath()
{
	return file_path;
}
int FileMorse::getDotFreaquency() { return dot_freaquency; }


void FileMorse::emmit(MorseCode message)
{
	std::fstream plik;
	plik.open(file_path, std::ios::out);
	
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

void FileMorse::setfilepath(std::string file_path)
{
	this->file_path = file_path;
}

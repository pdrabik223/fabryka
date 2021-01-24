#include "FileMorse.h"
#include <fstream>

FileMorse::FileMorse(std::string filepath)
{ // mo¿e wczytywanie danych z pluku? 

	this->filepath = filepath;
}

void FileMorse::emmit(MorseCode message)
{
	std::fstream plik;
	plik.open(filepath, std::ios::out);

	std::cout << plik.good()<<std::endl<<filepath;
	
	// moj wlasny encoding 
	// na wypadek czegos tam


	plik<<" dot_freaquency "<< dot_freaquency<<'\n';
	plik<<" dash_freaquency "<< dash_freaquency<<'\n';
	plik<<" dot_time "<< dot_time<<'\n';
	plik<<" dash_time "<< dash_time<<'\n';
	plik<<" pause_time "<< pause_time<<'\n';

	for (int letter = 0; letter < message.size(); letter++) {
	
		plik << message[letter];
	}


}

void FileMorse::setfilepath(std::string filepath)
{
	this->filepath = filepath;
}

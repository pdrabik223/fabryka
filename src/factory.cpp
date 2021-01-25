#include "factory.h"

std::vector<int> convertStrtoArr(std::string str)
{

	std::vector<int> arr;
	bool digit_string = false;

	for (int i = 0; i < str.length(); i++) {

		switch (str[i]) {
		case' ':case ',':case ';':case'\t':case'\n': // znaki "biale" 
			digit_string = false;
			break;
		case'0':case '1':case '2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':

			if (digit_string) {
				arr.back() *= 10;
				arr.back() += str[i] - 48;
			}
			else arr.push_back(str[i] - 48);
			digit_string = true;
			break;

		default:
			break;
		}
	}
	return arr;
}

// odczytywany plik musi byc zakodowany w specjalny sposob 
// FileMorse realizuje ten zapis
void  getFromFile(std::string path, std::map<std::string, int>& data) {
	std::fstream plik;


	plik.open(path, std::ios::in);
	if (!plik.good()) return;


	std::string temp;
	std::getline(plik, temp);
	if (temp != "MP") return;// sprawdzam czy plik zawiera odpowiedni encoding
	
	
	int value;
	do { // dane w pliku moga byc niepelne 
		// w takim przypdaku odczytane zostana tylko te wpisane 
		// reszta pozostanie default 
		std::getline(plik, temp, '\t');
		plik >> value;
		if (plik.good()) data[temp] = value;

	} while (plik.good());

	plik.close();


}

factory::factory()
{
	dot_freaquency = 800; // default values 
	dash_freaquency = 600;
	dot_time = 500;
	dash_time = 500;
	pause_time = 500;
	file_path = "no_path_given";
	morse = new ConsoleMorse(); // nie wymaga zadnych argumentow, przyjalem za defaultowy

}

factory::factory(const factory& other)
{
	dot_freaquency = other.dot_freaquency;
	dash_freaquency = other.dash_freaquency;
	dot_time = other.dot_time;
	dash_time = other.dash_time;
	pause_time = other.pause_time;
	file_path = other.file_path;


	morse = other.morse->clone();

}

factory& factory::operator=(const factory& other)
{
	if (this == &other) return *this;
	dot_freaquency = other.dot_freaquency;
	dash_freaquency = other.dash_freaquency;
	dot_time = other.dot_time;
	dash_time = other.dash_time;
	pause_time = other.pause_time;
	file_path = other.file_path;


	morse = other.morse->clone();


	return*this;
}


void factory::setExternalInfo()
{
	dot_freaquency = 800; // default values 
	dash_freaquency = 600;
	dot_time = 500;
	dash_time = 500;
	pause_time = 500;
	file_path = "no_path_given";

}

void factory::setExternalInfo(std::string input)
{



	if (input.size() > 4 && input.substr(input.size() - 4, input.size()) == ".txt") {


		std::map<std::string, int> data; // deklaruje tylko na potrzeby  getFromFile

		data["dot_freaquency"] = dot_freaquency;  // dafault values 
		data["dash_freaquency"] = dash_freaquency; // wstawiam wartosci domyslne
		data["dot_time"] = dot_time;
		data["dash_time"] = dash_time;
		data["pause_time"] = pause_time;





		getFromFile(input, data);
		this->file_path = input;



		// zapisywanie wartosci w zmiennej
	   // this->filepath na wypadek nie podania sciezki filepath po 
		this->dot_freaquency = data["dot_freaquency"];
		this->dash_freaquency = data["dash_freaquency"];
		this->dot_time = data["dot_time"];
		this->dash_time = data["dash_time"];
		this->pause_time = data["pause_time"];


	}
	else {
		std::vector<int> parsed_values = convertStrtoArr(input);

		switch (parsed_values.size()) {
		case 3: // nadpisywanie defautowych wartosci 
			dot_time = parsed_values[0];
			dash_time = parsed_values[1];
			pause_time = parsed_values[2];

			break;
		case 6: // 
			dot_freaquency = parsed_values[0];  // dafault values 
			dash_freaquency = parsed_values[1]; // wstawiam wartosci domysln

			dot_time = parsed_values[2];
			dash_time = parsed_values[3];
			pause_time = parsed_values[4];

			break;

		default:
			break;
		}

	}


}





void factory::setOutput(output type)
{
	switch (type) {
	case Beep:
		delete morse; // zwalniam pamiec 

		morse = new BeepMorse(this->dot_freaquency,
			this->dash_freaquency,
			this->dot_time,
			this->dash_time,
			this->pause_time); // przypisuje pozadany obiekt

		break;
	case Blink:
		delete morse;

		morse = new BlinkMorse(this->dot_time,
			this->dash_time,
			this->pause_time);

		break;
	case Console:
		delete morse;

		morse = new ConsoleMorse();
		
		break;
	case File:
		delete morse;

		morse = new FileMorse(this->file_path, this->dot_freaquency,
			this->dash_freaquency,
			this->dot_time,
			this->dash_time,
			this->pause_time);

		break;

	}

}

void factory::emmit(MorseCode message)
{
	morse->emmit(message);

}

void factory::set_filepath(std::string file_path)
{
	this->file_path = file_path;
}

void factory::set_dot_freaquency(int dot_freaquency)
{
	this->dot_freaquency = dot_freaquency;
}

void factory::set_dash_freaquency(int dash_freaquency)
{
	this->dash_freaquency = dash_freaquency;
}

void factory::set_dot_time(int dot_time)
{
	this->dot_time = dot_time;

}

void factory::set_dash_time(int dash_time)
{
	this->dash_time = dash_time;
}

void factory::set_pause_time(int pause_time)
{
	this->pause_time = pause_time;
}



std::string factory::getFilePath() { return file_path; }
int factory::getDashFreaquency() { return dash_freaquency; }
int factory::getDotTime() { return dot_time; }
int factory::getdashTime() { return dash_time; }
int factory::getPauseTime() { return pause_time; }
int factory::getDotFreaquency() { return dot_freaquency; }


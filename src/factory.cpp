#include "factory.h"
#include <map>

std::vector<int> convertStrtoArr(std::string str)
{

	std::vector<int> arr;
	bool digit_string = false;

	for (int i = 0; i < str.length(); i++) {

		switch (str[i]) {
		case' ':case ',':case ';':case'\t':case'\n':
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


void  getFromFile(std::string path, std::map<std::string, int>& data) {
	std::fstream plik;


	plik.open(path, std::ios::in);
	if (!plik.good()) return;


	std::string temp;
	std::getline(plik, temp);
	if (temp != "MP") return;// sprawdzam czy plik zawiera odpowiedni encoding
	int value;

	do {
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
	filepath = "no_path_given";
	morse = nullptr;

}

factory::factory(const factory& other)
{
	dot_freaquency = other.dot_freaquency;
	dash_freaquency = other.dash_freaquency;
	dot_time = other.dot_time;
	dash_time = other.dash_time;
	pause_time = other.pause_time;
	filepath = other.filepath;
	morse = other.morse;

}

factory& factory::operator=(const factory& other)
{
	if (this == &other) return *this;
	dot_freaquency = other.dot_freaquency;
	dash_freaquency = other.dash_freaquency;
	dot_time = other.dot_time;
	dash_time = other.dash_time;
	pause_time = other.pause_time;
	morse = other.morse;
	filepath = other.filepath;

	return*this;
}


void factory::setExternalInfo(std::string input)
{

	std::map<std::string, int> data;

	data["dot_freaquency"] = dot_freaquency;  // dafault values 
	data["dash_freaquency"] = dash_freaquency; // wstawiam wartosci domyslne
	data["dot_time"] = dot_time;
	data["dash_time"] = dash_time;
	data["pause_time"] = pause_time;



	if (input.size() > 4 && input.substr(input.size() - 4, input.size()) == ".txt") {
		 getFromFile(input, data);
		 this->filepath = input;
	}
	else {
		std::vector<int> parsed_values = convertStrtoArr(input);
	

		switch (parsed_values.size()) {
		case 3: // nadpisywanie defautowych wartosci 
			data["dot_time"] = parsed_values[0];
			data["dash_time"] = parsed_values[1];
			data["pause_time"] = parsed_values[2];
			
			break;
		case 6: // 
			data["dot_freaquency"] = parsed_values[0];  // dafault values 
			data["dash_freaquency"] = parsed_values[1]; // wstawiam wartosci domysln
			
			data["dot_time"] = parsed_values[2];
			data["dash_time"] = parsed_values[3];
			data["pause_time"] = parsed_values[4];

			break;

			default: 
				break;
		}

	}
	// zapisywanie wartosci w zmiennej
	// this->filepath na wypadek nie podania sciezki filepath po 
	this-> dot_freaquency = data["dot_freaquency"];
	this-> dash_freaquency = data["dash_freaquency"];
	this-> dot_time = data["dot_time"];
	this-> dash_time = data["dash_time"];
	this-> pause_time = data["pause_time"];

}





void factory::setOutput(output type)
{
	switch (type) {
	case Beep:
		if (morse != nullptr) delete morse;

		morse = new BeepMorse(this->dot_freaquency ,
		this->dash_freaquency ,
		this->dot_time ,
		this->dash_time ,
		this->pause_time);

		break;
	case Blink:
		if (morse != nullptr) delete morse;

		morse = new BlinkMorse(this->dot_freaquency,
			this->dash_freaquency,
			this->dot_time,
			this->dash_time,
			this->pause_time);

		break;
	case Console:
		if (morse != nullptr) delete morse;

		morse = new ConsoleMorse(this->dot_freaquency,
			this->dash_freaquency,
			this->dot_time,
			this->dash_time,
			this->pause_time);

		break;
	case File:
		if (morse != nullptr) delete morse;

		morse = new FileMorse(filepath, this->dot_freaquency ,
		this->dash_freaquency ,
		this->dot_time ,
		this->dash_time ,
		this->pause_time);

		break;

	}

}

void factory::emmit(MorseCode message)
{
	morse->emmit(message);

}

#include "factory.h"
/*
void factory::setAll(int dot_freaquency, int dash_freaquency, int dot_time,
	int dash_time, int pause_time) {
	morse->dot_freaquency = dot_freaquency;
	morse->dash_freaquency = dash_freaquency;
	morse->dot_time = dot_time;
	morse->dash_time = dash_time;
	morse->pause_time = pause_time;
}

void factory::setDotFreaquency(int dot_freaquency) {
	morse->dot_freaquency = dot_freaquency;
}

void factory::setDashFreaquency(int dash_freaquency) {
	morse->dash_freaquency = dash_freaquency;
}

void facory::setdashTime(int dash_time) { morse->dash_time = dash_time; }
void facory::setDotTime(int dot_time) { morse->dot_time = dot_time; }
void facory::setPauseTime(int pause_time) { morse->pause_time = pause_time; }
*/

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


factory::factory(const factory& other)
{
	morse = other.morse;

}

factory& factory::operator=(const factory& other)
{
	if (this == &other) return *this;
	morse = other.morse;

	return*this;
}

factory::factory(std::string input)
{

	if (input.size() > 4 && input.substr(input.size() - 4, input.size()) == ".txt") {
		morse = new FileMorse(input);
		return;
	}

	std::vector <int> variables = convertStrtoArr(input);

	std::cout << variables.size();

	for (int i = 0; i < variables.size(); i++) {
		std::cout << variables[i];
	}
	morse = new ConsoleMorse();


	switch (variables.size()) {
	case 0:
		morse = new ConsoleMorse();
		return;
	case 3:
		morse = new BlinkMorse(variables[0], variables[1], variables[2]);
		return;
	case 5:
		morse = new BeepMorse(variables[0], variables[1], variables[2], variables[3], variables[4]);
		return;






	}




}

void factory::emmit(MorseCode message)
{
	morse->emmit(message);

}

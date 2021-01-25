#include "BlinkMorse.h"

void numlockBind() {


    INPUT in[2];
    in[0].type = INPUT_KEYBOARD;
    in[0].ki.wVk = VK_NUMLOCK;
    in[0].ki.wScan = 0;
    in[0].ki.time = 0;
    in[0].ki.dwFlags = 0;
    in[0].ki.dwExtraInfo = 0;
    in[1] = in[0];
    in[1].ki.dwFlags = KEYEVENTF_KEYUP;
    ::SendInput(2, in, sizeof(INPUT));

}

BlinkMorse::BlinkMorse()
{
    dot_time = 500; // wartosci bazowe
    dash_time = 500;
    pause_time = 500;
}

BlinkMorse::BlinkMorse(int dot_time, int dash_time, int pause_time)
{
   this-> dot_time = dot_time; // wartosci bazowe
   this-> dash_time = dash_time;
   this-> pause_time = pause_time;
}


void BlinkMorse::setdashTime(int dash_time) { this->dash_time = dash_time; }
void BlinkMorse::setDotTime(int dot_time) { this->dot_time = dot_time; }
void BlinkMorse::setPauseTime(int pause_time) { this->pause_time = pause_time; }




void BlinkMorse::emmit(MorseCode message)
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "\n";
    for (auto letter = 0; letter < message.size(); letter++) {

        switch (message[letter]) {
        case '.':
            numlockBind();
            SetConsoleTextAttribute(hc, 8 + 8 * 16);
            std::cout << " ";
            
            Sleep(dot_time);
            
            numlockBind();
            SetConsoleTextAttribute(hc, 0 + 0 * 16);
            std::cout << "\r \r";
            break;
        case '-':
            numlockBind();
            SetConsoleTextAttribute(hc, 8 + 8 * 16);
            std::cout << "    ";
           
            Sleep(dash_time);

            numlockBind();
            SetConsoleTextAttribute(hc, 0 + 0 * 16);
            std::cout << "\r    \r";
            break;
        default:
            // beep space
            Sleep(pause_time);
           
            break;
        }
    }


}

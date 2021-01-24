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

BlinkMorse::BlinkMorse(const BlinkMorse& other)
{
    dot_freaquency = other.dot_freaquency;
    dash_freaquency = other.dash_freaquency;
    dot_time = other.dot_time;
    dash_time = other.dash_time;
    pause_time = other.pause_time;
}

BlinkMorse& BlinkMorse::operator=(const BlinkMorse& other)
{
    if (this == &other)
        return *this;
    dot_freaquency = other.dot_freaquency;
    dash_freaquency = other.dash_freaquency;
    dot_time = other.dot_time;
    dash_time = other.dash_time;
    pause_time = other.pause_time;

    return *this;
}

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

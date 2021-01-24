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
void consolecolorBind() {



}
void BlinkMorse::emmit(MorseCode message)
{

    for (auto letter = 0; letter < message.size(); letter++) {

        switch (message[letter]) {
        case '.':
            numlockBind();
            Sleep(dot_time);
            numlockBind();
            break;
        case '-':
            numlockBind();
            Sleep(dash_time);
            numlockBind();
            break;
        default:
            // beep space
            Sleep(pause_time);
            std::cout << " ";
            break;
        }
    }


}

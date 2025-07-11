#ifndef _PLAYERINPUT_H_
#define _PLAYERINPUT_H_
#include <Arduino.h>
#include <Ps3Controller.h>
class c_inputs{
    public:
    byte  PS3Input(bool p);
    bool InputTester(byte memory[], int p);

};
#endif
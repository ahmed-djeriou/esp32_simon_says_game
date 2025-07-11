#ifndef _LEDCONTROL_H_
#define _LEDCONTROL_H_
#include <Arduino.h>
class c_LED{
public :
void LEDlosing();
void LEDglory();
void LEDglow_sequence(byte memory[],int p);


};
#endif
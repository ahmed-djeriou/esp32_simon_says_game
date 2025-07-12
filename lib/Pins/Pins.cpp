#include<Pins.h>
 c_Pins::c_Pins() {
    redLED = 26;
    yellowLED = 25;
    greenLED = 27;
    green = false;
    red = false;
    yellow = false;
}
 
 void c_Pins :: update(){
    green = Ps3.data.button.cross;
    red = Ps3.data.button.circle;
    yellow = Ps3.data.button.triangle;
 }
 
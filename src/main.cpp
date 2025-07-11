#include <Arduino.h>
#include <Ps3Controller.h>
#include <game.h>
c_game smt;


void setup()
{
    Serial.begin(115200);
    Ps3.begin("01:02:03:04:05:06");
    Serial.println("Ready.");
    pinMode(27,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(25,OUTPUT);
}

void loop()
{
    if(Ps3.data.button.square){
      smt.game(1);  
    }
}



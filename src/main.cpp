#include <Arduino.h>
#include <Ps3Controller.h>
#include <game.h>
#include <Pins.h>
c_Pins leds;
c_game smt;


void setup()
{
    Serial.begin(115200);
    Ps3.begin("01:02:03:04:05:06");
    Serial.println("Ready.");
    pinMode(leds.greenLED,OUTPUT);
    pinMode(leds.redLED,OUTPUT);
    pinMode(leds.yellowLED,OUTPUT);
}

void loop()
{
  
    if(Ps3.data.button.square){
      smt.gamel(1);  
    }
}



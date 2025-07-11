#include<game.h>
#include<LEDcontrol.h>
#include<PlayerInput.h>
c_inputs button;
c_LED led;
void c_game :: gamel(int p){                                   /// the actual game 
  byte states[100];
  led.LEDglow_sequence(states,p);

  if(button.InputTester(states,p)){
    delay(700);
    led.LEDglory();
    delay(500);
    gamel(p+1);

  }else{
    led.LEDlosing();
  }
}
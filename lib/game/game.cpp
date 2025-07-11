#include<game.h>
#include<LEDcontrol.h>
#include<PlayerInput.h>
c_inputs idk;
c_LED idc;
void game(int p){                                   /// the actual game 
  byte states[100];
  idc.LEDglow_sequence(states,p);

  if(idk.InputTester(states,p)){
    delay(700);
    idc.LEDglory();
    delay(500);
    game(p+1);

  }else{
    idc.LEDlosing();
  }
}
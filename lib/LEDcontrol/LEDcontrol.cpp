#include<LEDcontrol.h>
#include<Pins.h>
c_Pins idk;
void LEDglory(){                                         
  byte LEDs[3]={idk.greenLED,idk.redLED,idk.yellowLED};
  for(int i=0;i<2;i++){  
  digitalWrite(LEDs[0],HIGH);
  delay(100);
  digitalWrite(LEDs[0],LOW);
  digitalWrite(LEDs[1],HIGH);
  delay(100);
  digitalWrite(LEDs[1],LOW);
  digitalWrite(LEDs[2],HIGH);
  delay(100);
  digitalWrite(LEDs[2],LOW);
  }
}
void LEDlosing(){
    byte LEDs[3]={idk.greenLED,idk.redLED,idk.yellowLED};
    digitalWrite(LEDs[0],LOW);
    digitalWrite(LEDs[1],HIGH);
    digitalWrite(LEDs[2],LOW);
    delay(200);
    digitalWrite(LEDs[1],LOW);
}
void LEDglow_sequence(byte memory[],int p){
  byte LEDs[3]={idk.greenLED,idk.redLED,idk.yellowLED};
  
  for(int i=0;i<p;i++){
    int num = random() % 3;
    digitalWrite(LEDs[num],HIGH);
    delay(500-(p*50));
    digitalWrite(LEDs[num],LOW);
    delay(500-(p*50));
   
    memory[i]=num;
    
  }
  digitalWrite(LEDs[0],HIGH);
  digitalWrite(LEDs[1],HIGH);
  digitalWrite(LEDs[2],HIGH);
  delay(500);
  digitalWrite(LEDs[0],LOW);
  digitalWrite(LEDs[1],LOW);
  digitalWrite(LEDs[2],LOW);
  delay(500);
}



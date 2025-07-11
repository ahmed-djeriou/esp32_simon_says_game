#include <Arduino.h>
#include <Ps3Controller.h>

#define redLED  26 //output
#define yellowLED  25
#define greenLED  27
bool green = Ps3.data.button.cross;
bool red = Ps3.data.button.circle;
bool yellow = Ps3.data.button.triangle;
void gloryLED(){
  byte LEDs[3]={greenLED,redLED,yellowLED};
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
void losingLED(){
    byte LEDs[3]={greenLED,redLED,yellowLED};
    digitalWrite(LEDs[0],LOW);
    digitalWrite(LEDs[1],HIGH);
    digitalWrite(LEDs[2],LOW);
    delay(200);
    digitalWrite(LEDs[1],LOW);
}
void glowLED(byte memory[],int p){
  byte LEDs[3]={greenLED,redLED,yellowLED};
  
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
byte  PS3Input(bool p){
    if(!p){
        return 25;
    }  
     if (Ps3.data.button.cross) {
     digitalWrite(greenLED, HIGH);
     return 0;
     } 
     if (Ps3.data.button.circle) {
        digitalWrite(redLED, HIGH);
        return 1;
     } 
     if (Ps3.data.button.triangle) {
     digitalWrite(yellowLED, HIGH);
     return 2;
     }
        

    
        return 25;
    

}
 bool InputTester(byte memory[], int p) {
    byte k;
    byte LEDs[3]={greenLED,redLED,yellowLED};

    for (int i = 0; i < p; i++) {
        bool pressed = false;
        while (!pressed) {
            k = PS3Input(ps3IsConnected());
            if (k == memory[i]) {   
                pressed = true;
                 while(PS3Input(ps3IsConnected()) != 25) {
                     delay(10); 
                    }     
            }
            else if (k != 25) {     
                return false;      
            }
        }
        digitalWrite(LEDs[0],LOW);
        digitalWrite(LEDs[1],LOW);
        digitalWrite(LEDs[2],LOW);
    }
    return true;  
}
void game(int p){
  byte states[100];
  glowLED(states,p);

  if(InputTester(states,p)){
    delay(700);
    gloryLED();
    delay(500);
    game(p+1);

  }else{
    losingLED();
  }
}


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
      game(1);  
    }
}



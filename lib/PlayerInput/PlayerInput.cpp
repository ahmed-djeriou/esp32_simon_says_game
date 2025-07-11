#include<PlayerInput.h>
#include<Pins.h>
c_Pins idk;
byte  PS3Input(bool p){                                              //input functions
    if(!p){
        return 25;
    }  
     if (idk.green) {
     digitalWrite(idk.greenLED, HIGH);
     return 0;
     } 
     if (idk.red) {
        digitalWrite(idk.redLED, HIGH);
        return 1;
     } 
     if (idk.yellow) {
     digitalWrite(idk.yellowLED, HIGH);
     return 2;
     }
        

    
        return 25;
    

}
 bool InputTester(byte memory[], int p) {
    byte k;
    byte LEDs[3]={idk.greenLED,idk.redLED,idk.yellowLED};

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
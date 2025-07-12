#include<PlayerInput.h>
#include<Pins.h>
c_Pins pin;
byte c_inputs :: PS3Input(bool p){                                              //input functions
    pin.update();
    if(!p){
        return 25;
    }  
     if (pin.green) {
     digitalWrite(pin.greenLED, HIGH);
     return 0;
     } 
     if (pin.red) {
        digitalWrite(pin.redLED, HIGH);
        return 1;
     } 
     if (pin.yellow) {
     digitalWrite(pin.yellowLED, HIGH);
     return 2;
     }
        

    
        return 25;
    

}
 bool c_inputs :: InputTester(byte memory[], int p) {
    byte k;
    byte LEDs[3]={pin.greenLED,pin.redLED,pin.yellowLED};

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
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

void main(){
    wiringPiSetupGpio() ;
    int i=0;
    int pins_leds[]={23,24,25,12,16,20,21,26};
    pinMode(17, INPUT);
    for(i=0;i<8;i++)
      pinMode(pins_leds[i], OUTPUT);

    while(digitalRead(17) != 1){
      for (i = 0; i < 8; i++){
        digitalWrite(pins_leds[i], 1);
        digitalWrite(pins_leds[7-i], 1);
        delay(500);
        digitalWrite(pins_leds[i], 0);
        digitalWrite(pins_leds[7-i], 0);

        if (digitalRead(17) == 1) break;
      }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "EasyPIO.h"

#define escape 27

extern void delay(int timer);

void fantastic(int timer){
    int i=0;
    int pins_leds[]={23,24,25,12,16,20,21,26};
    pioInit();
    pinMode(17, INPUT);
    for(i=0;i<8;i++)
      pinMode(pins_leds[i], OUTPUT);

    while(digitalRead(17) != escape ){
      for (i = 0; i < 8; ++i){
        digitalWrite(pins_leds[i], 1);
        digitalWrite(pins_leds[7-i], 1);
        delay(timer);
        digitalWrite(pins_leds[i], 0);
        digitalWrite(pins_leds[7-i], 0);

        if (digitalRead(17) == escape) break;
      }
    }
}

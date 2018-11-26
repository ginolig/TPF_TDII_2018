#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

void carrera(){
   wiringPiSetupGpio() ;
    int i=0, j=0;
    int lut[16][8]={
      {1,0,0,0,0,0,0,0},
      {1,0,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {1,0,0,0,1,0,0,0},
      {0,1,0,0,1,0,0,0},
      {0,0,1,0,0,1,0,0},
      {0,0,0,1,0,1,0,0},
      {0,0,0,0,1,0,1,0},
      {0,0,0,0,0,1,1,0},
      {0,0,0,0,0,0,1,1},
      {0,0,0,0,0,0,0,1}
    };
    int pins_leds[]={23,24,25,12,16,20,21,26};

    pinMode(17, INPUT);
    for(i=0;i<8;i++)
      pinMode(pins_leds[i], OUTPUT);

    while(digitalRead(17) != 1){
      for (i = 0; i < 16; i++){
        for(j=0;j<8;j++)
          digitalWrite(pins_leds[j], lut[i][j]);
      }
       if (digitalRead(17) == 1) break;
       delay(1000);
    }
}

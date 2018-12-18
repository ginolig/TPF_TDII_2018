#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

void rnd(int *stat);

int sec2(){
    wiringPiSetupGpio() ;
    int i=0, pin=0;
    int pins_leds[]={23,24,25,12,16,20,21,26};
    int stat[]={0,0,0,0,0,0,0,0};

    printf("USTED ESTA PRESENCIANDO LOS MISTERIOS DE LA ENTROPIA\n");
    printf("Pulse el maravilloso botón de la plaqueta para salir\n");

    pinMode(17, INPUT);
    for(i=0;i<8;i++)
      pinMode(pins_leds[i], OUTPUT);
    srand(time(NULL));

    while(digitalRead(17) != 1){
      rnd(stat);
      for(i=0;i<8;i++){
        digitalWrite(pins_leds[i], stat[i]);
        if (digitalRead(17) == 1) return 0;
      }
    	for (int i = 0; i < (rand()%1000)+1; ++i){ /*Genera numero aleatorio entre 1 y 1000*/
      		delay(1);
    	  	if (digitalRead(17) == 1) return 0;
		}
    }
}

void rnd(int stat[]){
  int i=0;
  for(i=0;i<8;i++)
    stat[i]=rand() % 2;   /*Genera aleatoriamente 0 o 1*/
}

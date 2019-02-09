#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

void sec1(){
    wiringPiSetupGpio() ;
    int i=0;
    int pins_leds[]={23,24,25,12,16,20,21,26}, estado[2][8]={{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1}};
    pinMode(17, INPUT);
    for(i=0;i<8;i++)
      pinMode(pins_leds[i], OUTPUT);
    srand(time(NULL));
	printf("USTED ESTA PRESENCIANDO LA MAGIA NAVIDE%cA\n", 165);
	printf("Pulse el destacado botón de la plaqueta para salir\n");

    while(digitalRead(17) != 1){
      for(i = 0; i < 8; i++){
        digitalWrite(pins_leds[i], estado[0][i]);
        if (digitalRead(17) == 1) break;
      }
      for (int i = 0; i < (rand()%10000)+100; ++i){ /*Genera numero aleatorio entre 100 y 10000*/
      	delay(1);
      	if (digitalRead(17) == 1) break;
      	}

      for(i = 0; i < 8; i++){
        digitalWrite(pins_leds[i], estado[1][i]);
        if (digitalRead(17) == 1) break;
      }
      delay(rand() % 1000 + 1);
    }
    for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
    system("clear");
}

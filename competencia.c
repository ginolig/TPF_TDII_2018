#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "funciones.h"


void main(){
	wiringPiSetupGpio() ;
	int pins_leds[]={23,24,25,12,16,20,21,26};
	

	pinMode(17, INPUT);
	for(k=0;k<8;k++) pinMode(pins_leds[k], OUTPUT);
	
	



for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
system("clear");
}



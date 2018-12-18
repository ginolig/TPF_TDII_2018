#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "funciones.h"


int intensidad(){
	wiringPiSetupGpio() ;
	char c;
	int pins_leds[]={23,24,25,12,16,20,21,26}, i, j, flag, retardo, balance=100, posicion=6;

	pinMode(17, INPUT);
	for(i=0;i<8;i++) pinMode(pins_leds[i], OUTPUT);	//declaro pines comno salidas

	while(1){
		if (digitalRead(17) == 1) return 0;
		for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 1);

		for(i=0;i<1024;i++){


			if(i==2) digitalWrite(pins_leds[balance%8], 0);
			if(i==8) digitalWrite(pins_leds[(balance+1)%8], 0);
			if(i==15) digitalWrite(pins_leds[(balance+2)%8], 0);
			if(i==30) digitalWrite(pins_leds[(balance+3)%8], 0);
			if(i==60) digitalWrite(pins_leds[(balance+4)%8], 0);
			if(i==200) digitalWrite(pins_leds[(balance+5)%8], 0);
			if(i==500) digitalWrite(pins_leds[(balance+6)%8], 0);
			if(i==1023) digitalWrite(pins_leds[(balance+7)%8], 0);

			delayMicroseconds(2);

		if(kbhit()){
        system("/bin/stty raw");
		if( c = getchar() == '[')      c = getchar();
			if( c  == 'A'){ //modo de observar si se pulso flecha abajo
				balance+=1;
				system("clear");
				printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
			else if ( c == 'B') { //flecha arriba
				balance-=1;
				system("clear");
				printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
        system("/bin/stty cooked");
		}

		}
	}
    for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
    system("clear");

}

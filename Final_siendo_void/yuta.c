#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "funciones.h"

int delay_mio();

int i, flag, retardo;


void yuta(){
	wiringPiSetupGpio() ;
	int  k;
	int pins_leds[]={23,24,25,12,16,20,21,26};
	pinMode(17, INPUT);
	for(k=0;k<8;k++) pinMode(pins_leds[k], OUTPUT);
	
	retardo=adc()/2;


	while(digitalRead(17) != 1){
		for (i = 0; i < 2; i++){		
			for(k=0;k<4;k++) digitalWrite(pins_leds[k], 1);
			delay_mio();
			if(i==1) delay_mio();
			for(k=0;k<4;k++) digitalWrite(pins_leds[k], 0);
			for(k=4;k<8;k++) digitalWrite(pins_leds[k], 1);
        		delay_mio();
			if(i==1) delay_mio();
			for(k=4;k<8;k++) digitalWrite(pins_leds[k], 0);

        	if(i==1){
			for(k=0;k<4;k++) digitalWrite(pins_leds[k], 1);
			delay_mio();
			for (k = 0; k < 4; k++){
		        	delay_mio();
		        	digitalWrite(pins_leds[k], 0);
		        }

		for(k=4;k<8;k++) digitalWrite(pins_leds[k], 1);
		delay_mio();
        	for (k = 7; k > 3; k--){
			delay_mio();
			digitalWrite(pins_leds[k], 0);
            		
            	}
        }
	delay_mio();
	if(i==1) delay_mio();
        if (digitalRead(17) == 1 || flag == 1) break;
      }
    }

    for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
    system("clear");
}

int delay_mio(){
	char c;
	int j;
	for (j = -1; j < retardo; ++j) //bucle de retardos 1 para poder salir cuando quiera
	        {
	            delay(2);
		    if(i!=1) delay(3);
	            if (digitalRead(17) == 1) { flag=1; break;} 
	         
		
			if(kbhit()){
		        system("/bin/stty raw");   
				if( c = getchar() == '[')      c = getchar();
					if( c  == 'A'){ //modo de observar si se pulso flecha abajo
						if(retardo != 0) retardo-=10; 
						j=-1; 
						system("clear"); 
						printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
					else if ( c == 'B') { //flecha arriba
						retardo+=10; 
						j=-1; 
						system("clear"); 
						printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
		        system("/bin/stty cooked");
		}
        }

}

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "funciones.h"

int apilada(){

	wiringPiSetupGpio();
	char c;
	int  retardo, j;
	int i=0, k, flag=0, mx=8;
	int pins_leds[]={23,24,25,12,16,20,21,26};
	pinMode(17, INPUT);
	for(i=0;i<8;i++) pinMode(pins_leds[i], OUTPUT);

	retardo = adc() ; //llamo al adc para ver su valo, si falla la comunicacion 125
        system("clear");
	printf("USTED ESTA HACIENDO USO DE LA INIGUALABLE APILADA\n");
	printf("Pulse el distinguido botón de la plaqueta para salir\n (PUEDE MODIFICAR LAS VELOCIDADES CON LAS FLECHAS UP AND DOWN)");
	i=0;
	while(1){
	      
		for (i = 0; i < 8; i++){
			for(k=0;k<mx;k++){
						
				        digitalWrite(pins_leds[k], 1);
				        for (j = -1; j < retardo; ++j) //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
				        {
				            delay(1);
				            if (digitalRead(17) == 1) { flag=1; return 0;} 
				         
					
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
        			
				        digitalWrite(pins_leds[k], 0);
	        	}

		mx=mx-1;
		digitalWrite(pins_leds[mx], 1);
		
	
	        if (digitalRead(17) == 1 || flag == 1) return 0;
		}
	
	for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
	i=0;
	k=0;
	mx=8;
	if (digitalRead(17) == 1 || flag == 1) return 0;
	}
    
    for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
    system("clear");

}

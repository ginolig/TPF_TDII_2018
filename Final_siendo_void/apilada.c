#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "funciones.h"

void apilada(int ch){

	wiringPiSetupGpio();
	char c, data_in;
	/*char   * uart  =  "/dev/ttyS0";   Descomentar al terminar de probar*/
	int  retardo, j, file_descriptor;
	static int cnt=0, retardo2=0;
	int i=0, k, flag=0, mx=8;
	int pins_leds[]={23,24,25,12,16,20,21,26};
	pinMode(17, INPUT);
	for(i=0;i<8;i++) pinMode(pins_leds[i], OUTPUT);

		retardo = adc() ; //llamo al adc para ver su valo, si falla la comunicacion 125
		if(cnt==0) retardo2=retardo;

		/*file_descriptor = serialOpen(uart, 9600);   Descomentar al terminar de probar*/

        system("clear");
	printf("USTED ESTA HACIENDO USO DE LA INIGUALABLE APILADA\n");
	printf("Pulse el maravilloso botón de la plaqueta para salir\n");
	i=0;
	while(1){

		for (i = 0; i < 8; i++){
			for(k=0;k<mx;k++){

				        digitalWrite(pins_leds[k], 1);
				        for (j = -1; j < retardo2; ++j) //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
				        {
				            delay(1);
				            if (digitalRead(17) == 1) { flag=1; break;}

					if(ch==0){
					if(kbhit()){
				        system("/bin/stty raw");
						if( c = getchar() == '[')      c = getchar();
							if( c  == 'A'){ //modo de observar si se pulso flecha abajo
								if(retardo2 != 0) retardo2-=10;
								j=-1;
								system("clear");
								printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
							else if ( c == 'B') { //flecha arriba
								retardo2+=10;
								j=-1;
								system("clear");
								printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
				        system("/bin/stty cooked");
						}
					}else if(ch==1){
						data_in  = serialGetchar(file_descriptor);
						serialFlush(file_descriptor);
		              if(data_in  == 'A'){ //modo de observar si se pulso flecha abajo
		                  if(retardo2 != 0) retardo2-=10;
		                  j=-1;
		                  system("clear");
		                  printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
		                else if ( data_in == 'B') { //flecha arriba
		                  retardo2+=10;
		                  j=-1;
		                  system("clear");
		                  printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
		            }
					}

				        digitalWrite(pins_leds[k], 0);
	        	}

		mx=mx-1;
		digitalWrite(pins_leds[mx], 1);


		if (digitalRead(17) == 1 || flag == 1){
			serialFlush(file_descriptor);
			serialClose(file_descriptor);
			break;
		}
		}

	for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
	i=0;
	k=0;
	mx=8;
	if (digitalRead(17) == 1 || flag == 1){
		serialFlush(file_descriptor);
		serialClose(file_descriptor);
		break;
	}
	}

    for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
    system("clear");

}

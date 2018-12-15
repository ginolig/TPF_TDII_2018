#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "funciones.h"

void choque(){
  
    wiringPiSetupGpio() ; //inicializo wiringPi 
    int i=0, retardo, flag, j;
    char c;
    int pins_leds[]={23,24,25,12,16,20,21,26};

    retardo = adc() ; //llamo al adc para ver su valo, si falla la comunicacion 125
    system("clear");
    printf("SIENTE EL CHOQUE\n");
    printf("Pulse el maravilloso botón de la plaqueta para salir\n");

    pinMode(17, INPUT);
    for(i=0;i<8;i++) pinMode(pins_leds[i], OUTPUT);	//declaro pines comno salidas
  

    while(digitalRead(17) != 1){ 	//empieza la magia
      for (i = 0; i < 8; i++){
        digitalWrite(pins_leds[i], 1);	//prendo de izq a derecha
        digitalWrite(pins_leds[7-i], 1); //prendo de derecha a izquierda 
	if (digitalRead(17) == 1) break; //si aprieto boton sale
		
		for (j = -1; j < retardo; ++j)  {  //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
	            delay(1);
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

        digitalWrite(pins_leds[i], 0);
        digitalWrite(pins_leds[7-i], 0);

        if (digitalRead(17) == 1 || flag == 1) break;
      }

		
		for (j = -1; j < 300; ++j)  {  //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
	            delay(1);
	            if (digitalRead(17) == 1) { flag=1; break;} 
	         
		
			if(kbhit()){
	        	system("/bin/stty raw");   
				if( c = getchar() == '[')      c = getchar();
					if( c  == 'A'){ //modo de observar si se pulso flecha abajo
						if(retardo != 0) retardo-=10; 
						system("clear"); 
						printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
					else if ( c == 'B') { //flecha arriba
						retardo+=10; 
						system("clear"); 
						printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
	      				system("/bin/stty cooked");
			}
		}	

    
    }

    for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
    system("clear");

}

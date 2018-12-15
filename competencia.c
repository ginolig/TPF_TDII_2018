#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "funciones.h"


void main(){
	wiringPiSetupGpio() ;
	char a;
	int pins_leds[]={23,24,25,12,16,20,21,26}, i, flag, retardo, balance, posicion=6;
	int lut[11][8]={
      {0,0,0,0,0,0,0,0},
      {1,0,0,0,0,0,0,0},
      {1,1,0,0,0,0,0,0},
      {0,1,1,0,0,0,0,0},
      {0,0,1,1,0,0,0,0},
      {0,0,0,1,1,0,0,0},
      {0,0,0,0,1,1,0,0},
      {0,0,0,0,0,1,1,0},
      {0,0,0,0,0,0,1,1},
      {0,0,0,0,0,0,0,1},
      {0,0,0,0,0,0,0,0}  
  	};
	

	pinMode(17, INPUT);
	
	retardo = adc();

	printf("USTED ESTA HACIENDO USO DE LA COMPETENCIA ROMPEAMISTADES\n");
	printf("Debe llevarse las luces para su costado apretando repetidamente las flechas\n");
	printf("(jugar con moderacion, prohibida la jugancia a menores de 18 años)\n");
	printf("\nPulse el botón destacado de la plaqueta para salir\n");

	for (i = 0; i < 7; ++i) digitalWrite(pins_leds[i], lut[posicion][i]); //inicializo en la posicion central

	while(flag != 1){
		balance = 0; //VARIABLE DE DETECCION DE DIFERENCIA DE CANTIDAD DE PULSADOS ENTRE JUGADORES
		if (digitalRead(17) == 1) break;
		for (j = -1; j < retardo; ++i)
		{
			if(kbhit()){
		        system("/bin/stty raw");   
				if( c = getchar() == '[') c = getchar();
				if( c  == 'A'){ //modo de observar si se pulso flecha abajo
					if(retardo != 0) retardo-=10; 
					j=-1; 
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");} 
				else if ( c == 'B') { //flecha arriba
					retardo+=10; 
					j=-1; 
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");} 
				else if ( c == 'C'){ //flecha derecha
					balance += 1;
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");}
				else if ( c == 'D'){ //flecha derecha
					balance -= 1;
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");} 
					
				system("/bin/stty cooked");
			}
			if (balance > 0 & posicion != 11) 
			{ 
				posicion += 1; 
				for (i = 0; i < 7; ++i) digitalWrite(pins_leds[i], lut[posicion][i]);
			}
			if (balance < 0 & posicion != 0) 
			{ 
				posicion -= 1; 
				for (i = 0; i < 7; ++i) digitalWrite(pins_leds[i], lut[posicion][i]);
			}
			else if (posicion == 0 || posicion == 11) 
			{	system("clear");
				if (posicion == 0) printf("¡¡¡GANO EL JUGADOR DE LA DERECHA!!!\n");
				if (posicion == 1) printf("¡¡¡GANO EL JUGADOR DE LA IZQUIERDA!!!!\n");

				printf("Si desea volver a jugar pulse 1, de lo contrario cualquier tecla\n");
				c = getchar();
				if( c != 1 ) flag=1;
			}
			
		if (digitalRead(17) == 1) break;
		}
	}


	for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
	system("clear");
}



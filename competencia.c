#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "funciones.h"


int competencia(){
	wiringPiSetupGpio() ;
	char c;
	int pins_leds[]={23,24,25,12,16,20,21,26}, i, j, flag, retardo, balance, posicion=6;
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
	
	retardo = adc() * 2;

	printf("USTED ESTA HACIENDO USO DE LA COMPETENCIA ROMPEAMISTADES\n");
	printf("Debe llevarse las luces para su costado apretando repetidamente las flechas\n");
	printf("(jugar con moderacion, prohibida la jugancia a menores de 18 años)\n");
	printf("\nPulse el botón destacado de la plaqueta para salir\n");

	for (i = 0; i < 8; ++i) digitalWrite(pins_leds[i], lut[posicion - 1][i]); //inicializo en la posicion central

	while(1){
		balance = 0; //VARIABLE DE DETECCION DE DIFERENCIA DE CANTIDAD DE PULSADOS ENTRE JUGADORES
		if (digitalRead(17) == 1 || flag == 1) return 0;
		for (j = -1; j < retardo; ++j)
		{	delay(1);
			if(kbhit()){
		        system("/bin/stty raw");   
				if( c = getchar() == '[') c = getchar();
				if( c  == 'A'){ //modo de observar si se pulso flecha abajo
					if(retardo != 0) retardo-=100; 
					j=-1; 
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");} 
				else if ( c == 'B') { //flecha arriba
					retardo+=100; 
					j=-1; 
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");} 
				else if ( c == 'C'){ //flecha derecha
					balance += 1;
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");}
				else if ( c == 'D'){ //flecha izquierda
					balance -= 1;
					system("clear"); 
					printf("Pulse el botón destacado de la plaqueta para salir\n");} 
					
			system("/bin/stty cooked");
			}
			if (digitalRead(17) == 1 || flag == 1) { return 0; flag==1;}
		}
		if (balance > 0 && posicion != 11) 
		{
			posicion += 1; 
			for (i = 0; i < 8; ++i) digitalWrite(pins_leds[i], lut[posicion - 1][i]);
		}
		if (balance < 0 && posicion != 1) 
		{ 
			posicion -= 1; 
			for (i = 0; i < 8; ++i) digitalWrite(pins_leds[i], lut[posicion - 1][i]);
		}

		if (posicion == 1 || posicion == 11) 
		{	system("clear");
			if (posicion == 11) printf("¡¡¡GANO EL JUGADOR DE LA DERECHA!!!\n");
			if (posicion == 1) printf("¡¡¡GANO EL JUGADOR DE LA IZQUIERDA!!!!\n");
			delay(1500);
			printf("Si desea volver a jugar pulse 1, de lo contrario cualquier tecla\n");
			system("/bin/stty raw");   
			while((c = getchar()) == '\n');
			system("/bin/stty cooked");
			system("clear");
			if( c != '1' ) { flag=1; return 0;}
			if (c == '1'){
				posicion = 6;
				for (i = 0; i < 8; ++i) digitalWrite(pins_leds[i], lut[posicion - 1][i]); //posicion central
				printf("USTED ESTA HACIENDO USO DE LA COMPETENCIA ROMPEAMISTADES\n");
				printf("Debe llevarse las luces para su costado apretando repetidamente las flechas\n");
				printf("(jugar con moderacion, prohibida la jugancia a menores de 18 años)\n");
				printf("\nPulse el botón destacado de la plaqueta para salir\n");
				

			}
		}
		
		if (digitalRead(17) == 1) return 0;
		
	}


	for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
	system("clear");
}



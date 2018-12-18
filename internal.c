#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int internal(int c) {
	int op;
	system("clear"); 

	do{
		system("clear");

		printf("Ingrese el modo que desea iniciar:");
		printf("\n\t 1- El auto fantastico ");
		printf("\n\t 2- La carrera");
		printf("\n\t 3- La apilada");
		printf("\n\t 4- El choque");
		printf("\n\t 5- Personalizado 1");
		printf("\n\t 6- Entropia");
		printf("\n\t 7- Eins Zwei Polizei");
		printf("\n\t 8- Contador 8bit");
		printf("\n\t 9- Competencia");
		printf("\n\t 10- Lumen");
		printf("\n\t 11- Seteo de velocidades mediante el uso de potenciometro");
		printf("\n\t 12- Salir. \n\t ");

		if(c==0)
			system("/bin/stty raw");   
			while((c = getchar()) == '\n');
			system("/bin/stty cooked");
			op=external();

		switch(op){

			case 1:
			fantastic();
			case 2:
			carrera();
			case 3:
			apilada();
			case 4:
			choque();
			case 5:
			sec1();
			case 6:
			sec2();
			case 7:
			yuta();
			case 8:
			contador();
			case 9:
			competencia();
			case 10:
			intensidad();
			case 11:
			adc();
			case 12:
			default:
			printf("Opcion invalida!\n");
			}
	}while(op=!12);
}

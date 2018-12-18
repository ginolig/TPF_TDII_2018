#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int internal(int c) {
	int op;

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
			scanf("%d", &op);
		else if(c==1)
			op=external();

		switch(op){

			case 1:
			fantastic();
			return 0; 
			case 2:
			carrera();
			return 0; 
			case 3:
			apilada();
			return 0; 
			case 4:
			choque();
			return 0; 
			case 5:
			sec1();
			return 0; 
			case 6:
			sec2();
			return 0; 
			case 7:
			yuta();
			return 0; 
			case 8:
			contador();
			return 0; 
			case 9:
			competencia();
			return 0; 
			case 10:
			intensidad();
			return 0; 
			case 11:
			adc();
			return 0; 
			case 12:
			return 0; 
			default:
			printf("Opcion invalida!\n");
			return 0; 
		}
	}while(op=!12);
}

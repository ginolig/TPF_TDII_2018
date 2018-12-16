#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void internal() {

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

		scanf("%d", &op);

		switch(op){

			case 1:
			fantastic();
			break;
			case 2:
			carrera();
			break;
			case 3:
			apilada();
			break;
			case 4:
			choque();
			break;
			case 5:
			sec1();
			break;
			case 6:
			sec2();
			break;
			case 7:
			yuta();
			break;
			case 8:
			contador();
			break;
			case 9:
			competencia();
			break;
			case 10:
			intensidad();
			break;
			case 11:
			adc();
			break;
			case 12:
			break;
			default:
			printf("Opcion invalida!\n");
			break;
		}
	}while(op=!12);
}

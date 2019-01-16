#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <wiringPi.h>

void internal(int choise) {
	int c=0;
	char op;
	c = choise;
	wiringPiSetupGpio() ;
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
		printf("\n\t a- Lumen");
		printf("\n\t b- Salir. \n\t ");

		if(c==0){

			scanf("%c", &op);
			system("clear");
		}
		else if(c==1)
			printf("opcion: %c", op=external());



		if(op == '1') fantastic(c);
		else if(op == '2') carrera(c);
		else if(op == '3') apilada(c);
		else if(op == '4') choque(c);
		else if(op == '5') sec1();
		else if(op == '6') sec2();
		else if(op == '7') yuta(c);
		else if(op == '8') contador(c);
		else if(op == '9') competencia(c);
		else if(op == 'a') intensidad(c);


	}while(op != 'b');
}

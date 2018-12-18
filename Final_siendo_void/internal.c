#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"
#include <wiringPi.h>

void internal(int choise) {
	int op, c=0;
	FILE *fp = fopen("./myfile", "a");
	c = choise;
	wiringPiSetupSys();
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
		printf("\n\t 11- Salir. \n\t ");

		if(c==0){
			__fpurge(fp);
 
			scanf("%d", &op);

			system("clear");
		}
		else if(c==1)
			op=external();

	

		if(op == 1) fantastic();
		else if(op == 2) carrera();
		else if(op == 3) apilada();
		else if(op == 4) choque();
		else if(op == 5) sec1();
		else if(op == 6) sec2();
		else if(op == 7) yuta();
		else if(op == 8 ) contador();
		else if(op == 9) competencia();
		else if(op == 10) intensidad();
		
		
	}while(op != 11);
}

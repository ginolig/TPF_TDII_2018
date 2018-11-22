#include <stdlib.h>
#include <stdio.h>

extern int adc();
extern void fantastic(int timer);

void main(){
	int op, timer;
	system("clear");

	printf("Ingrese el modo que desea iniciar:");
	printf("\n\t 1- El auto fantastico ");
	printf("\n\t 2- La carrera");
	printf("\n\t 3- La apilada");
	printf("\n\t 4- El choque");
	printf("\n\t 5-");
	printf("\n\t 6-");
	printf("\n\t 7-");
	printf("\n\t 8-");
	printf("\n\t 9- Seteo de velocidades mediante el uso de potenciometro");
	printf("\n\t 10- Posicion de los switches de entrada \n\t ");

	scanf("%d", &op);

	switch(op){

		case 1:
		timer = adc();
		fantastic(timer);
		break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		default:
	}
}

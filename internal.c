#include <stdio.h>
#include <stdlib.h>

extern void adc(int *tiempo);
extern void fantastic(int t);
extern void carrera(int t);
extern void apilada(int t);
extern void choque(int t);
extern void sec1();
extern void sec2();

void main() {
int op, tiempo[]={200,300,500,750,100,100,100,100};

	do{
		system("clear");

		printf("Ingrese el modo que desea iniciar:");
		printf("\n\t 1- El auto fantastico ");
		printf("\n\t 2- La carrera");
		printf("\n\t 3- La apilada");
		printf("\n\t 4- El choque");
		printf("\n\t 5- Personalizado 1");
		printf("\n\t 6- Personalizado 2");
		printf("\n\t 7- Personalizado 3");
		printf("\n\t 8- Personalizado 4");
		printf("\n\t 9- Seteo de velocidades mediante el uso de potenciometro");
		printf("\n\t 10- Salir. \n\t ");

		scanf("%d", &op);

		switch(op){

			case 1:
			printf("<<< El auto fantastico >>>\n");
			fantastic(tiempo[op-1]);
			break;
			case 2:
			printf("<<< La carrera >>>\n");
			carrera(tiempo[op-1]);
			break;
			case 3:
			printf("<<< La apilada >>>\n");
			apilada(tiempo[op-1]);
			break;
			case 4:
			printf("<<< El choque >>>\n");
			choque(tiempo[op-1]);
			break;
			case 5:
			sec1();
			break;
			case 6:
			sec2();
			break;
			case 7:
			case 8:
			case 9:
			adc(tiempo);
			break;
			case 10:
			break;
			default:
			printf("Opcion invalida!\n");
			break;
		}
	}while(op=!10);
}

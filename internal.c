#include <stdio.h>
extern int adc();
extern int fantastic();

void main() {
int op, time;
	system("clear"); 

	printf("Ingrese el modo que desea iniciar:");
	printf("\n\t 1- El auto fantastico ");	
	printf("\n\t 2- ");		
	printf("\n\t 3-");		
	printf("\n\t 4-");		
	printf("\n\t 5-");		
	printf("\n\t 6-");		
	printf("\n\t 7-");		
	printf("\n\t 8-");		
	printf("\n\t 9- Seteo de velocidades mediante el uso de los potenciometros ");		
	printf("\n\t 10- Posicion de los switches de entrada \n\t ");	

scanf("%d", &op);

	switch(op)

		case 1: 
		time= adc();
		fantastic(time); 
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
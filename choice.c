#include <stdio.h>
#include <stdlib.h>

int choice(){

int a, flag=0;

system("clear"); 	
	
printf("Seleccione la procedencia de los datos\n 1- Perifericos locales \n 2- Comunicacion serie \n");

while(flag==0){
	scanf("%d", &a);
	if (a==1)	return 0;
	else if (a==2)	return 1;
	else printf("\n El numero ingresado es invalido, intente nuevamente\n");
	
}

}
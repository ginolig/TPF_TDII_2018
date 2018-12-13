#include <stdio.h>
#include <stdlib.h>

int main(){

char a;

system("clear"); 	
printf("Seleccione la procedencia de los datos\n 1- Perifericos locales \n 2- Comunicacion serie \n");

while(1){
	scanf("%c", &a);
	if (a=='1')	return 0;
	else if (a=='2')	return 1;
	else if (a == '\n'); //en el buffer queda un enter que ensuciaba la leida
	else printf("\n El numero ingresado es invalido, intente nuevamente\n");

	
}

}

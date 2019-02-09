#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "funciones.h"

char   * uart  =  "/dev/serial0";

int main(){
	wiringPiSetupGpio ();
	int file_descriptor, flag=0;
	char   data_out, c, op;

	printf("Inicializando puerto...\n");


	if ((file_descriptor = serialOpen(uart, 9600)) < 0) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}else system("clear");

		do{
			system("clear");
			printf("\n\t\t<<< CENTRO DE CONTROL REMOTO >>>\n\n");
			printf("Escoja una opcion: \n");
			printf("1) Seleccionar secuencia\n");
			printf("2) Cambiar velocidad\n");
			printf("3) Salir.\n");

			scanf("%c", &op);

			if(op == '1'){
				data_out=getchar();
				serialFlush(file_descriptor);
				serialPutchar(file_descriptor, data_out=getchar());
				printf("data out: %c \n", data_out);
			}
			else if(op=='2'){
				flag = 0;
				while(flag!=1){
					if(kbhit()){
                    system("/bin/stty raw");
                if( c = getchar() == '[')      c = getchar();
                  if( c  == 'A'){ //modo de observar si se pulso flecha abajo
                    data_out='A';
					serialPutchar(file_descriptor, data_out);
					flag=1;}
				else if ( c == 'B') { //flecha arriba
					  data_out='B';
					serialPutchar(file_descriptor, data_out);
					flag=1;}
				else if ( c == 'C'){ //flecha derecha
					data_out='C';
					serialPutchar(file_descriptor, data_out);
					flag=1;}
				else if ( c == 'D'){ //flecha izquierda
					data_out='D';
					serialPutchar(file_descriptor, data_out);
					flag=1;}
                    system("/bin/stty cooked");
                }
				}
				serialFlush(file_descriptor);
			}

		}while(op != '3');

	serialFlush(file_descriptor);
	serialClose(file_descriptor);

return 0;
}

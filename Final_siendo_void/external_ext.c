#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <curses.h>

int cts=9;
int rts=10;

char   * uart  =  "/dev/ttyS0";

int main(){

	wiringPiSetupGpio ();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor;
	char   data_out;

	printf("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 9600);

	if (file_descriptor == -1) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
		do{
			printf("\t\t<<< CENTRO DE CONTROL REMOTO >>>\n\n");
			printf("Escoja una opcion: \n");
			serialFlush(file_descriptor);

			data_out = getchar();
			serialPutchar(file_descriptor, data_out);

		}while(data_out != 12);

	serialFlush(file_descriptor);
	serialClose(file_descriptor);


return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <curses.h>

int cts=9;
int rts=10;

char   * uart  =  "/dev/ttyS0";

int external(){

	wiringPiSetupGpio ();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor, rts, cts, flag, espera, data_out;
	char  handshaking;

	printf("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 9600);

	if (file_descriptor == -1) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
		do{
			printf("\t\t<<< CENTRO DE CONTROL REMOTO >>>\n\n");
			printf("Escoja una opcion: \n");
			scanf("%d", &data_out);
			serialPrintf (file_descriptor, data_out);
			digitalWrite( cts, 0);
			flag=0;
			while(flag < 10000){ //while de 10 seg de espera para que el receptor aparezca para recibir

				if (digitalRead(10)==0) break;	//leo si está en cero rts, de ser asi es que puede recibir algo
			delay(1);
			flag=flag+1;
			}
			if(flag==10000){
				serialFlush(file_descriptor);
				printf("No se ha podido establecer la conexion!\nSe ha vaciado el buffer de datos.\n");
			}
		}while(data_out != 12);

	serialClose(file_descriptor);
	digitalWrite( cts, 1);
	serialFlush(file_descriptor);
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <curses.h>

int cts=9;
int rts=10;

char   * uart  =  "/dev/ttyS0";

int external(){

	wiringPiSetupGpio();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor, rts, cts, caracteres, data_in, flag, espera;
	char  handshaking;

	printf("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 9600);

	if (file_descriptor == -1) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
		
	while(salir!=1){
		espera=0;
		caracteres=0;
	
	while(1){ //recibo datos		
		
		caracteres=serialDataAvail(file_descriptor); //me fijo cuantos caracteres hay dosponibles para enviar
		for (int i = 0; i < caracteres; ++i){
			data_in = serialGetchar(file_descriptor); //tomo el caracter y lo muestro en pantalla
			return data_in;
			}
		if(caracteres!=0){ salir=1; break;}
		delay(1000);
		espera++;
		}
	}

	serialClose(file_descriptor);
	digitalWrite( cts, 1);
	serialFlush(file_descriptor);
return 0;
}

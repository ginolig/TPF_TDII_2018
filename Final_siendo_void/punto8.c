#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <curses.h>

int cts=9;
int rts=10;

char   * uart  =  "/dev/ttyS0";

int main(){

	wiringPiSetupGpio();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor, salir=0, caracteres, flag, espera;
	char  data_in[2];

	//printf("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 9600);

	if (file_descriptor == -1) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
	
		while(salir != 1){ //recibo datos
		flag=0;
		espera=0;
		caracteres=0;

		//printf(" Esperando dato por 10 segundos.... \n");
		while(1){
			caracteres = serialDataAvail(file_descriptor); //me fijo cuantos caracteres hay dosponibles para enviar
			for (int i = 0; i < caracteres; ++i){
				if( i < 2)  data_in [i] = serialGetchar(file_descriptor); //tomo el caracter
				else devolucion();
			}
			//if(caracteres!=0) { salir=1; break;}
			delay(1000);
			espera++;
				
		}
		if(espera == 10) printf("NO SE PUDO ESTABLECER CONEXION");
		digitalWrite( cts, 1); //significa que no hay mas comunicacion
		}


	serialClose(file_descriptor);
	digitalWrite( cts, 1);
	serialFlush(file_descriptor);
return data_in;
}



		
		
		
	

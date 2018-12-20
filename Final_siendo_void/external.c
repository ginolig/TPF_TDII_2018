#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <curses.h>

int retorno(char data);

int cts=9;
int rts=10;

char   * uart  =  "/dev/ttyS0";

int external(){

	wiringPiSetupGpio();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor, salir=0, caracteres, dat;
	char data_in;

	printf("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 9600);

	if (file_descriptor == -1) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
	
		while(salir != 1){ //recibo datos



		caracteres=0;

		//printf(" Esperando dato por 10 segundos.... \n");
		while(1){
			
			caracteres = serialDataAvail(file_descriptor); //me fijo cuantos caracteres hay dosponibles para enviar
			if(caracteres != 0) {
				printf("ss%dss", caracteres);
				data_in  = serialGetchar(file_descriptor); //tomo el caracter y lo muestro en pantalla
				printf("%c", data_in);
				serialFlush(file_descriptor);
				}

				
			//	dat = retorno(data_in); 
			//  return dat;
				

			}
			//if(caracteres!=0) return data_in[0];
	//		if(caracteres!=0) { salir=1; break;}
	//		delay(1000);
	//		espera++;
				
		}
		
		

	serialFlush(file_descriptor);
	serialClose(file_descriptor);
	digitalWrite( cts, 1);
	
return 0;
}

int retorno(char data){
	if(data == 1) return 1;
	if(data == 2) return 2;
	if(data == 3) return 3;
	if(data == 4) return 4;
return 0;
	}

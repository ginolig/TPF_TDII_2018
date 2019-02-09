#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>

char   * uart  =  "/dev/serial0";

char external(){

	wiringPiSetup();
	int file_descriptor, salir=0;
	char data_in;

	printf("Inicializando puerto...\n");
	fflush(stdout);


	if ((file_descriptor = serialOpen(uart, 9600)) < 0) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
		
		while(salir != 1){ //recibo datos
			serialFlush(file_descriptor);
			delay(500);
			if(serialDataAvail(file_descriptor) > 0){
				data_in  = serialGetchar(file_descriptor); //tomo el caracter y lo muestro en pantalla
				salir=1;
				return data_in;
			}else{
				printf("error");
				break;
			}
	serialClose(file_descriptor);
}
return 0;
}

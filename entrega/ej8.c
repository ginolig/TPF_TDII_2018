#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#define cts  9
#define rts 10
char   * uart  =  "/dev/ttyACM0"

int main(){

	wiringPiSetupGpio ();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor, rts, cts, accion, caracteres, data_in;
	char *  data_out[100];

	printf("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 115200);

	if (file_descriptor == -1) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
		do {
		printf("Si usted desea recibir datos presione 1, si desea enviar presione 2, para salir presione 3\n");
		accion= getch();

		if(accion==1){ //recibo datos
			while(flag < 10000){ //while de 10 seg de espera para que el emisor aparezca para enviar 

				if (digitalRead(rts)==0){ //leo si está en cero rts, de ser asi es que quiere enviar algo
					digitalWrite( cts, 0); //significa que está listorti para comunicarse
					break;
					}	
			
			delay(1);
			flag=flag+1;

			}

			if (flag!=10000){ //hago uso de una artimaña. si flag es 10000 significa que no se establecio conexion en los 10seg
				caracteres=serialDataAvail(file_descriptor); //me fijo cuantos caracteres hay dosponibles para enviar
				for (int i = 0; i < caracteres; ++i){
					data_in = serialGetchar(file_descriptor);
					printf("%c \n", data_in);
				}
			}
		}

		else if(accion==2){
			printf("Escriba lo que desea enviar\n");
			scanf("%s", data_out);
			digitalWrite( cts, 0);
			serialPrintf (file_descriptor, data_out);

		}

	} while(accion != 3);

	serialClose(file_descriptor);
	digitalWrite( cts, 1);

}
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
	int file_descriptor, rts, cts, accion, caracteres, data_in, flag, espera;
	char  data_out[100], handshaking;

	printf("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 9600);

	if (file_descriptor == -1) {
		printf("El puerto no pudo abrirse\n");
		return 1;
	}
		do {
		printf(" ");
		printf("\n Si usted desea recibir datos presione 1, si desea enviar presione 2, para salir presione 3\n");
		accion= getchar();

		if(accion=='1'){ //recibo datos
			flag=0;
			espera=0;
			caracteres=0;
			printf("Para utilizar handshaking presione 1, de lo contrario cuanlquier otra tecla\n");
			delay(10);
			while(handshaking = getchar() == '\n'); //El buffer queda sucio por lo que si el char ingresado es 'salto de linea' no lo reconoce
			if(handshaking == 1){
				while(flag < 10000){ //while de 10 seg de espera para que el emisor aparezca para enviar

					if (digitalRead(10)==0){ //leo si está en cero rts, de ser asi es que quiere enviar algo
						digitalWrite( cts, 0); //significa que está listorti para comunicarse
						break;
						}

					delay(1);
					flag=flag+1;

					}
				}
			delay(1000);


			if (flag!=10000){ //hago uso de una artimaña. si flag es 10000 significa que no se establecio conexion en los 10seg
				printf(" Esperando dato por 10 segundos.... \n");
				while(espera!=10){
					caracteres=serialDataAvail(file_descriptor); //me fijo cuantos caracteres hay dosponibles para enviar
					for (int i = 0; i < caracteres; ++i){
						data_in = serialGetchar(file_descriptor); //tomo el caracter y lo muestro en pantalla
						printf("%c", data_in);
						}
					if(caracteres!=0) break;
					delay(1000);
					espera++;
					}
			}
			if(espera == 10) printf("NO SE PUDO ESTABLECER CONEXION");
		digitalWrite( cts, 1); //significa que no hay mas comunicacion
		}

		else if(accion=='2'){
			printf("Escriba lo que desea enviar\n");
			scanf("%s", data_out);
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



		}

	} while(accion != '3');

	serialClose(file_descriptor);
	digitalWrite( cts, 1);
	serialFlush(file_descriptor);
return 0;
}

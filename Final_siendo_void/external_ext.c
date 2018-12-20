#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <curses.h>
#include <conio.h>

int cts=9;
int rts=10;

char   * uart  =  "/dev/ttyS0";

int main(){

	wiringPiSetupGpio ();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor, op;
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
			printf("1) Seleccionar secuencia\n");
			printf("2) Cambiar velocidad\n");
			serialFlush(file_descriptor);
			scanf("%d",&op);
			if(op==1){
				data_out = getchar();
				serialPutchar(file_descriptor, data_out);
			}else if(op==2){
				if(kbhit()){
			        system("/bin/stty raw");
					if( c = getchar() == '[')      c = getchar();
						if( c  == 'A'){ //modo de observar si se pulso flecha abajo
							data_out=c;
							serialPutchar(file_descriptor, data_out);}
						else if ( c == 'B') { //flecha arriba
							data_out=c;
							serialPutchar(file_descriptor, data_out);
						}
						else if ( c == 'C'){ //flecha derecha
							data_out=c;
							serialPutchar(file_descriptor, data_out);}
						else if ( c == 'D'){ //flecha izquierda
							data_out=c;
							serialPutchar(file_descriptor, data_out);}
			        system("/bin/stty cooked");
					}
			}

		}while(data_out != 'b');

	serialFlush(file_descriptor);
	serialClose(file_descriptor);


return 0;
}

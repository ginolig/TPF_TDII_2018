#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "funciones.h"

int cts=9;
int rts=10;

char   * uart  =  "/dev/ttyS0";

int main(){

	wiringPiSetupGpio ();
	pinMode(rts, INPUT) ;
	pinMode(cts, OUTPUT) ;
	int file_descriptor, flag=0;
	char   data_out, c, op;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("Inicializando puerto...\n");

	file_descriptor = serialOpen(uart, 9600);

	if (file_descriptor == -1) {
		printw("El puerto no pudo abrirse\n");
		return 1;
	}else system("clear");

		while(file_descriptor){
			printw("\n\t\t<<< CENTRO DE CONTROL REMOTO >>>\n\n");
			printw("Escoja una opcion: \n");
			printw("1) Seleccionar secuencia\n");
			printw("2) Cambiar velocidad\n");

			while((op = getchar()) == '\n');
			printf("%c", op);
			if(op == '1'){
				serialFlush(file_descriptor);
				while((data_out=getchar()) == '\n');
				serialFlush(file_descriptor);
				serialPutchar(file_descriptor, data_out);
			}
			else if(op=='2'){
				flag = 0;
				while(flag!=1){
				if((data_out=getchar() != '\n')){
						if( (c = getchar()) == KEY_DOWN){ //modo de observar si se pulso flecha abajo
							data_out='A';
							serialPutchar(file_descriptor, data_out);
							flag=1;}
						else if ( c == KEY_UP) { //flecha arriba
							data_out='B';
							serialPutchar(file_descriptor, data_out);
							flag=1;
						}
						else if ( c == KEY_RIGHT){ //flecha derecha
							data_out='C';
							serialPutchar(file_descriptor, data_out);
							flag=1;}
						else if ( c == KEY_LEFT){ //flecha izquierda
							data_out='D';
							serialPutchar(file_descriptor, data_out);
							flag=1;}
					}
				}
				serialFlush(file_descriptor);
			}

		}

	serialFlush(file_descriptor);
	serialClose(file_descriptor);

endwin();
return 0;
}

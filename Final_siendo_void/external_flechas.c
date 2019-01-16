#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "funciones.h"

int main(){

    wiringPiSetupGpio() ;

    int i, j, retardo, flag=0, file_descriptor, ch;
    static int cnt=0, retardo2=0;
    char c, data_in;
    char   * uart  =  "/dev/ttyS0";
    int pins_leds[]={23,24,25,12,16,20,21,26};
    
    file_descriptor = serialOpen(uart, 9600);

    pinMode(17, INPUT);
    for(i=0;i<8;i++)        //defino como entrada pines
      pinMode(pins_leds[i], OUTPUT);

    retardo = (adc() / 10) * 10; //para que sea multiplo de 10 y no nos complique la vida
    if(cnt==0) retardo2=retardo;


 system("clear");
    printf("USTED ESTA HACIENDO USO DEL INIGUALABLE AUTO FANTASTICO\n");
    printf("hholaaa");
    printf("Pulse el maravilloso botón de la plaqueta para salir\n");

    while(digitalRead(17) != 1){
      printf("1hholaaa");
      for (i = 0; i < 8; i++){
   	digitalWrite(pins_leds[i], 1);
        digitalWrite(pins_leds[7-i], 1);
        
printf("2hholaaa");

       if (digitalRead(17) == 1) break;
       printf("3hholaaa");
        for (j = -1; j < retardo2; ++j) //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
        {
            delay(1);
            if (digitalRead(17) == 1) { flag=1; break;}

			

            if(ch==0){
            if(kbhit()){
                  system("/bin/stty raw");
              if( c = getchar() == '[')      c = getchar();
                if( c  == 'A'){ //modo de observar si se pulso flecha abajo
                  if(retardo2 != 0) retardo2-=10;
                  j=-1;
                  system("clear");
                  printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
                else if ( c == 'B') { //flecha arriba
                  retardo2+=10;
                  j=-1;
                  system("clear");
                  printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
                  system("/bin/stty cooked");
              }
            }else if(ch==1){
				printf("aaaaaaaaa");
				data_in  = serialGetchar(file_descriptor);
				printf("bbbbbbbbbbb");
				serialFlush(file_descriptor);
              if(data_in  == 'A'){ //modo de observar si se pulso flecha abajo
                  if(retardo2 != 0) retardo2-=10;
                  j=-1;
                  system("clear");
                  printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
                else if ( data_in == 'B') { //flecha arriba
                  retardo2+=10;
                  j=-1;
                  system("clear");
                  printf("Pulse el maravilloso botón de la plaqueta para salir\n");}
            }
	}


        digitalWrite(pins_leds[i], 0);
        digitalWrite(pins_leds[7-i], 0);

        if (digitalRead(17) == 1 || flag == 1) break;
      }
    }
    for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
    system("clear");

}

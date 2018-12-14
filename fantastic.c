#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <curses.h>

extern int adc();
extern int kbhit();

void main(){
  
    wiringPiSetupGpio() ;
 
    int i, j, retardo, flag=0;
    char c;
    int pins_leds[]={23,24,25,12,16,20,21,26};

    pinMode(17, INPUT); 
    for(i=0;i<8;i++)        //defino como entrada pines
      pinMode(pins_leds[i], OUTPUT);

    retardo = (adc() / 10) * 10; //para que sea multiplo de 10 y no nos complique la vida
 
  
 system("clear");
    printf("USTED ESTA HACIENDO USO DEL INIGUALABLE AUTO FANTASTICO\n");
    printf("Pulse el maravilloso botón de la plaqueta para salir\n");

    while(digitalRead(17) != 1){
      for (i = 0; i < 8; i++){
   	digitalWrite(pins_leds[i], 1);
        digitalWrite(pins_leds[7-i], 1);

       if (digitalRead(17) == 1) break;
        for (j = -1; j < retardo; ++j) //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
        {
            delay(1);
            if (digitalRead(17) == 1) { flag=1; break;} 
         
	
	if(kbhit()){
        system("/bin/stty raw");   
		if( c = getchar() == '[')      
			if( c = getchar() == 'A'){ //modo de observar si se pulso flecha abajo
				if(retardo != 0) retardo-=10; 
				j=-1; 
				system("clear"); 
				printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
			else  { //flecha arriba
				retardo+=10; 
				j=-1; 
				system("clear"); 
				printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
        system("/bin/stty cooked");
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

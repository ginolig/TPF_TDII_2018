#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//#include <curses.h>

extern int adc();
extern int kbhit();

int main(){

	wiringPiSetupGpio();
	char c;
	int  retardo, j;
	int i=0, k, flag=0, mx=8;
	int pins_leds[]={23,24,25,12,16,20,21,26};
	pinMode(17, INPUT);
	for(i=0;i<8;i++) pinMode(pins_leds[i], OUTPUT);

	retardo = adc() ; //llamo al adc para ver su valo, si falla la comunicacion 125
        system("clear");
	printf("USTED ESTA HACIENDO USO DE LA INIGUALABLE APILADA\n");
	printf("Pulse el maravilloso botón de la plaqueta para salir\n");
	i=0;
	while(1){
	      
		for (i = 0; i < 8; i++){
			for(k=0;k<mx;k++){
						
				        digitalWrite(pins_leds[k], 1);

					for (j = -1; j < retardo; ++j) //bucle de retardos 1 para poder salir cuando quiera
				        {
				            delay(1);
				            if (digitalRead(17) == 1) { flag=1; break;} 
				         
					
						if(kbhit()){ //detecto si pulso una tecliña
					        system("/bin/stty raw");   //el buffer se vacia sin esperar intro
							if( c = getchar() == '[')      
								if( c = getchar() == 'A'){ //modo de observar si se pulso flecha abajo //detecto si es flecha arriba y disminuyo retardo
									if(retardo != 0) retardo-=10; 
									j=-1; 
									system("clear"); 
									printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
								else  { 		//detecto si es flecha abajo y aumento retardo
									retardo+=10; 
									j=-1; 
									system("clear"); 
									printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
					        system("/bin/stty cooked"); //pongo el buffer como corresponde
						}
			        	}
			
				        digitalWrite(pins_leds[k], 0);
	        	}

		mx=mx-1;
		digitalWrite(pins_leds[mx], 1);
		
	
	        if (digitalRead(17) == 1 || flag == 1) break;
		}
	
	for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
	i=0;
	k=0;
	mx=8;
	if (digitalRead(17) == 1 || flag == 1) break;
	}
    
    for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
    system("clear");

}

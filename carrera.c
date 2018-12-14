#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

extern int adc();
extern int kbhit();

void main(int t){

  wiringPiSetupGpio() ;
  char c;
  int i=0, j=0, retardo, flag=0;
  int lut[16][8]={
      {1,0,0,0,0,0,0,0},
      {1,0,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {1,0,0,0,1,0,0,0},
      {0,1,0,0,1,0,0,0},
      {0,0,1,0,0,1,0,0},
      {0,0,0,1,0,1,0,0},
      {0,0,0,0,1,0,1,0},
      {0,0,0,0,0,1,1,0},
      {0,0,0,0,0,0,1,1},
      {0,0,0,0,0,0,0,1}
  };
  int pins_leds[]={23,24,25,12,16,20,21,26};

  printf("USTED ESTA HACIENDO USO DE LA MAGIA CARRERISTICA\n");
  printf("Pulse el maravilloso botón de la plaqueta para salir\n");

  retardo = adc();
  pinMode(17, INPUT);
  for(i=0;i<8;i++)
    pinMode(pins_leds[i], OUTPUT);

  while(digitalRead(17) != 1){
    for (i = 0; i < 16; i++){
      for(j=0;j<8;j++)
        digitalWrite(pins_leds[j], lut[i][j]);
        if (digitalRead(17) == 1) break;
      
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
	   if (digitalRead(17) == 1) break;
	   }

    }
    for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
    system("clear");
}

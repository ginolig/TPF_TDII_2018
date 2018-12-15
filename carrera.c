#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

extern int adc();
extern int kbhit();

void carrera(int t){

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

  retardo = adc();

  printf("USTED ESTA HACIENDO USO DE LA MAGIA CARRERISTICA\n");
  printf("Pulse el maravilloso botón de la plaqueta para salir\n");


  pinMode(17, INPUT);
  for(i=0;i<8;i++)
    pinMode(pins_leds[i], OUTPUT);

  while(digitalRead(17) != 1){
    for (i = 0; i < 16; i++){
      for(j=0;j<8;j++)
        digitalWrite(pins_leds[j], lut[i][j]);
        if (digitalRead(17) == 1) break;
	      for (j = -1; j < retardo; ++j) //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
	        {
	            delay(1);
	            if (digitalRead(17) == 1) { flag=1; break;} 
	         
		
		if(kbhit()){
	        system("/bin/stty raw");   
			if( c = getchar() == '[')      c = getchar();
				if( c  == 'A'){ //modo de observar si se pulso flecha abajo
					if(retardo != 0) retardo-=10; 
					j=-1; 
					system("clear"); 
					printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
				else if ( c == 'B') { //flecha arriba
					retardo+=10; 
					j=-1; 
					system("clear"); 
					printf("Pulse el maravilloso botón de la plaqueta para salir\n");} 
	        system("/bin/stty cooked");
			}
		}
	   if (digitalRead(17) == 1) break;
	   }

    }
    for(i=0;i<8;i++)  digitalWrite(pins_leds[i], 0);
    system("clear");
}

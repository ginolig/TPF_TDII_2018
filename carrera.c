#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
extern int adc();

void carrera(int t){
  initscr();
  wiringPiSetupGpio() ;
  char c;
  int i=0, j=0, retardo;
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

  retardo = adc() * 8;
  pinMode(17, INPUT);
  for(i=0;i<8;i++)
    pinMode(pins_leds[i], OUTPUT);

  while(digitalRead(17) != 1){
    for (i = 0; i < 16; i++){
      for(j=0;j<8;j++)
        digitalWrite(pins_leds[j], lut[i][j]);
        if (digitalRead(17) == 1) break;
      
        for (j = 1; i < retardo; ++i){ //hago el retardo dividido retardo por si aprieto para apagar cuando este esta sucediendo
            delay(retardo/retardo);
            if (digitalRead(17) == 1) flag=1; 
            noecho();
            flushinp();
            if(c = getch() == '\033')   if( c = getch() == '[')      if( c = getch() == 'A') retardo+=50; //modo de observar si se pulso flecha arriba
            if(c = getch() == '\033')   if( c = getch() == '[')      if( c = getch() == 'B') retardo+=50; //modo de observar si se pulso flecha abajo
            echo(); 

        } 
	   if (digitalRead(17) == 1) break;
	   }

    }
   for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
    endwin();
}

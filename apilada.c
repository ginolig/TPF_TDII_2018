#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <curses.h>
extern int adc();

void apilada(){
    initscr();
    wiringPiSetupGpio();
    char c;
    int i=0, max=8, retardo;
    int pins_leds[]={23,24,25,12,16,20,21,26};
    pinMode(17, INPUT);
    for(i=0;i<8;i++)
      pinMode(pins_leds[i], OUTPUT);

    retardo = adc() * 8;
        system("clear");
    printf("USTED ESTA HACIENDO USO DE LA INIGUALABLE APILADA\n");
    printf("Pulse el maravilloso botón de la plaqueta para salir\n");

    while(digitalRead(17) != 1){
      
      for (i = 0; i < max; i++){
        digitalWrite(pins_leds[i], 1);
        digitalWrite(pins_leds[i], 0);
        
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

        if(i==(max-1)){
          digitalWrite(pins_leds[i], 1);
          digitalWrite(pins_leds[i], 0);
          digitalWrite(pins_leds[i], 1);
          if (digitalRead(17) == 1) break;
        }

        if (digitalRead(17) == 1) break;
      }
    }
    
    for(i=0;i<8;i++) digitalWrite(pins_leds[i], 0);
    endwin();
}

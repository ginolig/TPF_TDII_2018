    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    #include<EasyPIO.h>

#define escape          27

 extern void delay(int time);
 
void   fantastic( int time;){

    int pins_leds[]={23,24,25,12,16,20,21,26};
   
        

        while(digitalRead(17) != escape ){ 

        for (int i = 0; i < 8; ++i)
        {
            

            digitalWrite(pins_leds[i], 1);
            digitalWrite(pins_leds[7-i], 1);
            delay(time);
            digitalWrite(pins_leds[i], 0);
            digitalWrite(pins_leds[7-i], 0);

            if (digitalRead(17) == escape) break;

        }

    }
    }

 

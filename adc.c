#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char arduino = 0x22; // direccion base

void adc(){

  wiringPiSetupGpio();
  pinMode(17, INPUT);
  int l=0, op=0,fd, adcVal;;

  fd = wiringPiI2CSetup(arduino);		// configuracion del bus I2C, inicializa el sistema I2C con el ID del dispositivo.	
  if(fd != (-1)) {
    wiringPiI2CWrite(fd, 0);  //solicita leer la entrada analógica A0 del mux del arduino
  	wiringPiI2CRead(fd); //primer lectura
  	adcVal = wiringPiI2CRead(fd);//segunda lectura valida
  }
  else {
    printf("No se pudo leer el valor del potenciometro...\n");
    adcVal=125;
  }
return adcVal;

}

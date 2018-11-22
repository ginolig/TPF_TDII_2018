#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char arduino = 0x22; // direccion base

int fd, adcVal;	//declaracion de variables para acceder al adc

int main(){

  if (wiringPiSetup() == -1) exit (1);

  fd = wiringPiI2CSetup(arduino);		// configuracion del bus I2C, inicializa el sistema I2C con el ID del dispositivo.

  while (1){
  	//read ADC0
  	wiringPiI2CReadReg8(fd, arduino + 0); //primer lectura
  	adcVal = wiringPiI2CReadReg8(fd, arduino + 0);//segunda lectura valida
  	printf("Pote1 = %d \n", adcVal);
  	//read ADC1
  	wiringPiI2CReadReg8(fd, arduino + 1);
  	adcVal = wiringPiI2CReadReg8(fd, arduino + 1);
  	printf("Pote2 = %d \n", adcVal);
  	//read ADC2
  	wiringPiI2CReadReg8(fd, arduino + 2);
  	adcVal = wiringPiI2CReadReg8(fd, arduino + 2);
  	printf("Pote3 = %d \n\n", adcVal);
    //read ADC3
  	wiringPiI2CReadReg8(fd, arduino + 3);
  	adcVal = wiringPiI2CReadReg8(fd, arduino + 3);
  	printf("Pote4 = %d \n\n", adcVal);

  	delay(500);

  }

  return 0;

}

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char arduino = 0x22; // direccion base

int fd, adcVal;	//declaracion de variables para acceder al adc

int main(){

  wiringPiSetup();

  fd = wiringPiI2CSetup(arduino);		// configuracion del bus I2C, inicializa el sistema I2C con el ID del dispositivo.

  while (1){
  	//read A0
    wiringPiI2CWrite(fd, 0);  //solicita leer la entrada analógica A0 del mux del arduino
  	wiringPiI2CRead(fd); //primer lectura
  	adcVal = wiringPiI2CRead(fd);//segunda lectura valida
  	printf("A0 = %d \n", adcVal);
  	//read A1
    wiringPiI2CWrite(fd, 1);
  	wiringPiI2CRead(fd);
  	adcVal = wiringPiI2CRead(fd);
  	printf("A1 = %d \n", adcVal);
  	//read A2
    wiringPiI2CWrite(fd, 2);
    wiringPiI2CRead(fd);
  	adcVal = wiringPiI2CRead(fd);
  	printf("A2 = %d \n\n", adcVal);
    //read A3
    wiringPiI2CWrite(fd, 3);
    wiringPiI2CRead(fd);
  	adcVal = wiringPiI2CRead(fd);
  	printf("A3 = %d \n\n", adcVal);

  	delay(500);

  }

  return 0;

}

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char arduino = 0x22; // direccion base
int val(int adcVal);

int fd, adcVal;	//declaracion de variables para acceder al adc

void adc(int tiempo[]){

  wiringPiSetupGpio();
  pinMode(17, INPUT);
  int l=0, op=0;

  fd = wiringPiI2CSetup(arduino);		// configuracion del bus I2C, inicializa el sistema I2C con el ID del dispositivo.

  while (l == 1){
  	//read A0
    wiringPiI2CWrite(fd, 0);  //solicita leer la entrada analógica A0 del mux del arduino
  	wiringPiI2CRead(fd); //primer lectura
  	adcVal = wiringPiI2CRead(fd);//segunda lectura valida
    printf("Velocidad: %d %\n", adcVal);
    printf("Elegir este valor? (0=si, 1=no)\n");
    scanf("%d", &l);
  	delay(500);
    system("clear");
  }
  printf("A que secuencia desea cambiarle la velocidad?\n");
  printf("\n\t 1- El auto fantastico ");
	printf("\n\t 2- La carrera");
	printf("\n\t 3- La apilada");
	printf("\n\t 4- El choque");
	printf("\n\t 5- Personalizado 1");
	printf("\n\t 6- Personalizado 2");
	printf("\n\t 7- Personalizado 3");
	printf("\n\t 8- Personalizado 4\n");

  scanf("%d", &op);

  switch(op){
    case 1:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    case 2:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    case 3:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    case 4:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    case 5:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    case 6:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    case 7:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    case 8:
    tiempo[op-1]=tiempo[op-1]*val(adcVal);
    break;
    default:
    printf("Opcion invalida!\n");
    break;
  }
}

int val(int adcVal){
  int r=0;
  r=adcVal/100;
  return r;
}

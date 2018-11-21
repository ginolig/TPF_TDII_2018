#include <EasyPIO.h>

void salida();

void main(){
	int a=0;
	
	while(a!=0){
		if(digitalRead(17)==1){
			salida();
			a=1;
		}
	}
}

void salida(){
	digitalWrite(23,digitalRead(5));
	digitalWrite(24,digitalRead(6));
	digitalWrite(25,digitalRead(13));
	digitalWrite(12,digitalRead(19));
}

void fantastic(){
	
	
}
	

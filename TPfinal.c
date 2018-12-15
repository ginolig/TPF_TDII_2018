#include <stdio.h>
#include "funciones.h"

void main(){
int state, place;

state= ingreso();

if(state==1) {
	place=choice();

	 if(place==0) internal();
	 else if (place==1) external();
	}


}

#include <stdio.h>
#include "funciones.h"

void main(){
int state, place, c=0;

state= ingreso();

if(state==1) {
	place=choice();

	 if(place==0)
	 	c=0;
	 else if (place==1)
	 	c=1;
	internal(c);}
}

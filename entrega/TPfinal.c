#include <stdio.h>

extern int	ingreso();
extern int choice();
extern void internal();
extern void external();

void main(){
int state, place;

state= ingreso();

if(state=1) {
	place= choice();

	 if(place==0) internal();
	 else if (place==1) external();
	}


}



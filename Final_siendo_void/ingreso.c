#include <stdio.h>
#include <curses.h>
#define ENTER 10
#define BORRAR 127


char password[5];
char mypass[]={'p','a','s','s','w'};


int ingreso(){
int i=0, j=0, k, correcta=0, ch;
initscr();
noecho();  //Para que no se vea en consola los caracteres tipeados

printw(" Intento %d de 3. \n Ingrese su clave de 5 digitos: \t", i+1);
printw("\n");

for(i=0; i<3; i++){ //Bucle que cuenta 3 intentos de ingreso de clave
	for(j=0;j<5;j++){ //bucle de carga  y control de clave
		ch= getch(); //función de entrada de datos



		if(ch == ENTER) { j=6; correcta=0;} //Si pulsa enter se sale del bucle de carga

		else if (ch == BORRAR){ //bucle de borrado
			j=j-2; //vuelvo j 2 espacios para sobrescribir el dato ingresado erroneamente
			deleteln(); //limpio la linea

			for(k=0;k<=j;k++){printw("%c", '*');}
				      }

		else if (ch != BORRAR) { 					//si no borra, carga el dato

			printw("%c", '*');
			password[j]=ch;
			}
	}
 for(int k=0;k<5;k++){ //control de clave
			// printw("%c", password[k]); sirve al programador para ver por pantalla la clave cargada en el vector
			if(password[k]==mypass[k]) correcta=1; //Si la clave ingresada es igual al password se pone la bandera a 1
			else correcta=0; // De ser distintas se limpia la bandera de clave correcta

}

if(correcta==1){
	printw("\n\t\t Usted ha ingresado correctamente.\n"
			"\n\t\t Presione una tecla para continuar\n");
	getch();
	break;
}

else printw("\n Vuelva a probar, restan %d intentos.\n", 2-i);
}
echo(); //se vuelven a visualizar los caracteres ingresados
if(correcta==0)
	printw("No se ha obtenido acceso. Terminando programa...\n");
endwin();
   return correcta;
}

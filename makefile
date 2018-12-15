# -----------------------------------------------------------------
# Makefile trabajo final TDII 2018
# -----------------------------------------------------------------

CC = gcc

OBJECTS = TPfinal.o adc.o ingreso.o choice.o internal.o external.o fantastic.o carrera.o apilada.o choque.o sec1.o sec2.o kbhit.o yuta.o

CFLAGS = -lwiringPi -pthread -lcrypt -lm -lrt -lncurses

TPfinal.o: TPfinal.c funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) TPfinal.c -c -o TPfinal.o
	
adc.o: adc.c
	$(CC) $(CFLAGS) adc.c -c -o adc.o
	
ingreso.o: ingreso.c
	$(CC) $(CFLAGS) ingreso.c -c -o ingreso.o
	
choice.o: choice.c
	$(CC) $(CFLAGS) choice.c -c -o choice.o
	
kbhit.o: kbhit.c
	$(CC) $(CFLAGS) kbhit.c -c -o kbhit.o
	
sec1.o: sec1.c
	$(CC) $(CFLAGS) sec1.c -c -o sec1.o
	
sec2.o: sec2.c
	$(CC) $(CFLAGS) sec2.c -c -o sec2.o
	
internal.o: internal.c funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) internal.c -c -o internal.o
	
fantastic.o: fantastic.c funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) fantastic.c -c -o fantastic.o
	
carrera.o: carrera.c funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) carrera.c -c -o carrera.o
	
apilada.o: apilada.c funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) apilada.c -c -o apilada.o
	
choque.o: choque.c funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) choque.c -c -o choque.o
	
yuta.o: yuta.c funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) yuta.c -c -o yuta.o
	
final: $(OBJECTS) funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) -o final

clean:
	rm *.o

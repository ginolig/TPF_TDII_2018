# -----------------------------------------------------------------
# Makefile trabajo final TDII 2018
# -----------------------------------------------------------------

CC = gcc

OBJECTS = TPfinal.o adc.o ingreso.o choice.o internal.o external.o fantastic.o carrera.o apilada.o choque.o sec1.o sec2.o kbhit.o yuta.o competencia.o contador.o intensidad.o

CFLAGS = -lwiringPi -pthread -lcrypt -lm -lrt -lncurses

final: $(OBJECTS) funciones.h
	$(CC) $(CFLAGS) $(OBJECTS) -o final

clean:
	rm *.o

# -----------------------------------------------------------------
# Makefile trabajo final TDII 2018
# -----------------------------------------------------------------

CC = gcc

OBJECTS = TPfinal.o adc.o ingreso.o choice.o internal.o external.o fantastic.o carrera.o apilada.o choque.o sec1.o sec2.o kbhit.o yuta.o

CFLAGS = -lwiringPi -pthread -lcrypt -lm -lrt -lncurses

TPfinal.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) TPfinal.c -c -o TPfinal.o
	
adc.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) adc.c -c -o adc.o
	
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
	
internal.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) internal.c -c -o internal.o
	
fantastic.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) fantastic.c -c -o fantastic.o
	
carrera.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) carrera.c -c -o carrera.o
	
apilada.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) apilada.c -c -o apilada.o
	
choque.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) choque.c -c -o choque.o
	
yuta.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) yuta.c -c -o yuta.o
	
final: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o final

clean:
	rm *.o

CC = gcc
CFLAGS = -Wall -c
LFLAGS = -Wall -o

all: tarea1

tarea1: main.o libevento.o
	$(CC) $(LFLAGS) tarea1

main.o: main.c
	$(CC) $(CFLAGS) main.c

libevento.o: lib/libevento.a include/evento.h
	$(CC) $(CFLAGS) -lm lib/libevento.a     ¿ASI SE COMPILA UNA LIBRERIA ESTATICA?
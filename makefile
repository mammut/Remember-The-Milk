CC = gcc
CFLAGS = -Wall -c
LDFLAGS= -L./lib -levento

all: tarea1

tarea1: main.o libevento.o
	$(CC) main.o $(LDFLAGS) -o tarea1

main.o: main.c
	$(CC) main.c $(CFLAGS)

libevento.o: evento.o
	ar rcs lib/libevento.a evento.o

evento.o: include/evento.h evento.c
	$(CC) $(CFLAGS) evento.c

clean:
	find . -name '*.a' -type f -delete
	find . -name '*.o' -type f -delete
	rm tarea1
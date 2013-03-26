CC = gcc
CFLAGS = -Wall -c
LDFLAGS= -L./lib -levento

all: tarea1

tarea1: main.o libevento.o function.o
	$(CC) main.o function.o $(LDFLAGS) -o tarea1

main.o: main.c
	$(CC) main.c $(CFLAGS)

function.o: function.c function.h
	$(CC) $(CFLAGS) $<

libevento.o: evento.o
	mkdir -p lib
	ar rcs lib/libevento.a $<

evento.o: evento.c include/evento.h
	$(CC) $(CFLAGS) $<

clean:
	rm -rf lib
	find . -name '*.o' -type f -delete
	rm -f tarea1

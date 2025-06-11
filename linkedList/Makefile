# Variables
CC = gcc
CFLAGS = -Wall -g

# Objetivo final
main: main.o linkedList.o
	$(CC) $(CFLAGS) -o main main.o linkedList.o

# Cómo generar los archivos .o
main.o: main.c linkedList.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

# Limpieza
clean:
	rm -f *.o main

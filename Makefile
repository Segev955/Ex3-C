CC=gcc
Ar=ar
FLAGS = -Wall -g
OBJECT_MAIN=main.o

all: main.o stringProg

stringProg: $(OBJECT_MAIN)
	$(CC) $(FLAGS) -o stringProg $(OBJECT_MAIN)
	
main.o: main.c main.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg

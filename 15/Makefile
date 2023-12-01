CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 15a 15b

15a: 15a.o
	${CC} ${CFLAGS} -o $@ 15a.c

15b: 15b.o
	${CC} ${CFLAGS} -o $@ 15b.c

.PHONY: clean

clean:
	rm 15a.o 15a 15b.o 15b

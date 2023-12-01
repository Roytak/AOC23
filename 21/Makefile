CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 21a 21b

21a: 21a.o
	${CC} ${CFLAGS} -o $@ 21a.c

21b: 21b.o
	${CC} ${CFLAGS} -o $@ 21b.c

.PHONY: clean

clean:
	rm 21a.o 21a 21b.o 21b

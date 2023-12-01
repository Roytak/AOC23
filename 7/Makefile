CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 7a 7b

7a: 7a.o
	${CC} ${CFLAGS} -o $@ 7a.c

7b: 7b.o
	${CC} ${CFLAGS} -o $@ 7b.c

.PHONY: clean

clean:
	rm 7a.o 7a 7b.o 7b

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 9a 9b

9a: 9a.o
	${CC} ${CFLAGS} -o $@ 9a.c

9b: 9b.o
	${CC} ${CFLAGS} -o $@ 9b.c

.PHONY: clean

clean:
	rm 9a.o 9a 9b.o 9b

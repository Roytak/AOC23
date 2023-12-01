CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 2a 2b

2a: 2a.o
	${CC} ${CFLAGS} -o $@ 2a.c

2b: 2b.o
	${CC} ${CFLAGS} -o $@ 2b.c

.PHONY: clean

clean:
	rm 2a.o 2a 2b.o 2b

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 13a 13b

13a: 13a.o
	${CC} ${CFLAGS} -o $@ 13a.c

13b: 13b.o
	${CC} ${CFLAGS} -o $@ 13b.c

.PHONY: clean

clean:
	rm 13a.o 13a 13b.o 13b

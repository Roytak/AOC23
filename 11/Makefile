CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 11a 11b

11a: 11a.o
	${CC} ${CFLAGS} -o $@ 11a.c

11b: 11b.o
	${CC} ${CFLAGS} -o $@ 11b.c

.PHONY: clean

clean:
	rm 11a.o 11a 11b.o 11b

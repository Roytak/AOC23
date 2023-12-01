CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 10a 10b

10a: 10a.o
	${CC} ${CFLAGS} -o $@ 10a.c

10b: 10b.o
	${CC} ${CFLAGS} -o $@ 10b.c

.PHONY: clean

clean:
	rm 10a.o 10a 10b.o 10b

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 5a 5b

5a: 5a.o
	${CC} ${CFLAGS} -o $@ 5a.c

5b: 5b.o
	${CC} ${CFLAGS} -o $@ 5b.c

.PHONY: clean

clean:
	rm 5a.o 5a 5b.o 5b

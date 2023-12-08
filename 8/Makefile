CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -O3

all: 8a 8b

8a: 8a.o
	${CC} ${CFLAGS} -o $@ 8a.c

8b: 8b.o
	${CC} ${CFLAGS} -o $@ 8b.c

.PHONY: clean

clean:
	rm 8a.o 8a 8b.o 8b

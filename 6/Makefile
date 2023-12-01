CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 6a 6b

6a: 6a.o
	${CC} ${CFLAGS} -o $@ 6a.c

6b: 6b.o
	${CC} ${CFLAGS} -o $@ 6b.c

.PHONY: clean

clean:
	rm 6a.o 6a 6b.o 6b

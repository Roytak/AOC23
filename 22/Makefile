CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 22a 22b

22a: 22a.o
	${CC} ${CFLAGS} -o $@ 22a.c

22b: 22b.o
	${CC} ${CFLAGS} -o $@ 22b.c

.PHONY: clean

clean:
	rm 22a.o 22a 22b.o 22b

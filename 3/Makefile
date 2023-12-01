CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 3a 3b

3a: 3a.o
	${CC} ${CFLAGS} -o $@ 3a.c

3b: 3b.o
	${CC} ${CFLAGS} -o $@ 3b.c

.PHONY: clean

clean:
	rm 3a.o 3a 3b.o 3b

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 18a 18b

18a: 18a.o
	${CC} ${CFLAGS} -o $@ 18a.c

18b: 18b.o
	${CC} ${CFLAGS} -o $@ 18b.c

.PHONY: clean

clean:
	rm 18a.o 18a 18b.o 18b

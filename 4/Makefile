CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 4a 4b

4a: 4a.o
	${CC} ${CFLAGS} -o $@ 4a.c

4b: 4b.o
	${CC} ${CFLAGS} -o $@ 4b.c

.PHONY: clean

clean:
	rm 4a.o 4a 4b.o 4b

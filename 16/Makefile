CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 16a 16b

16a: 16a.o
	${CC} ${CFLAGS} -o $@ 16a.c

16b: 16b.o
	${CC} ${CFLAGS} -o $@ 16b.c

.PHONY: clean

clean:
	rm 16a.o 16a 16b.o 16b

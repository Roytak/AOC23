CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 17a 17b

17a: 17a.o
	${CC} ${CFLAGS} -o $@ 17a.c

17b: 17b.o
	${CC} ${CFLAGS} -o $@ 17b.c

.PHONY: clean

clean:
	rm 17a.o 17a 17b.o 17b

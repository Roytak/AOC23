CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 23a 23b

23a: 23a.o
	${CC} ${CFLAGS} -o $@ 23a.c

23b: 23b.o
	${CC} ${CFLAGS} -o $@ 23b.c

.PHONY: clean

clean:
	rm 23a.o 23a 23b.o 23b

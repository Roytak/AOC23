CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 14a 14b

14a: 14a.o
	${CC} ${CFLAGS} -o $@ 14a.c

14b: 14b.o
	${CC} ${CFLAGS} -o $@ 14b.c

.PHONY: clean

clean:
	rm 14a.o 14a 14b.o 14b

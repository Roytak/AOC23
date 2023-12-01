CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 20a 20b

20a: 20a.o
	${CC} ${CFLAGS} -o $@ 20a.c

20b: 20b.o
	${CC} ${CFLAGS} -o $@ 20b.c

.PHONY: clean

clean:
	rm 20a.o 20a 20b.o 20b

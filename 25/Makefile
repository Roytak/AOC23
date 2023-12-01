CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 25a 25b

25a: 25a.o
	${CC} ${CFLAGS} -o $@ 25a.c

25b: 25b.o
	${CC} ${CFLAGS} -o $@ 25b.c

.PHONY: clean

clean:
	rm 25a.o 25a 25b.o 25b

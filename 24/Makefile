CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 24a 24b

24a: 24a.o
	${CC} ${CFLAGS} -o $@ 24a.c

24b: 24b.o
	${CC} ${CFLAGS} -o $@ 24b.c

.PHONY: clean

clean:
	rm 24a.o 24a 24b.o 24b

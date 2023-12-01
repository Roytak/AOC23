CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 19a 19b

19a: 19a.o
	${CC} ${CFLAGS} -o $@ 19a.c

19b: 19b.o
	${CC} ${CFLAGS} -o $@ 19b.c

.PHONY: clean

clean:
	rm 19a.o 19a 19b.o 19b

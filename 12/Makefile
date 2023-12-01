CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: 12a 12b

12a: 12a.o
	${CC} ${CFLAGS} -o $@ 12a.c

12b: 12b.o
	${CC} ${CFLAGS} -o $@ 12b.c

.PHONY: clean

clean:
	rm 12a.o 12a 12b.o 12b

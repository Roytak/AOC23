#!/bin/bash

CONTENTS="
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
	FILE *f = fopen(\"in.txt\", \"r\");

	return 0;
}

"

for ((day = 2; day <= 25; day++)); do
	mkdir -p ${day}
	echo "$CONTENTS" > ${day}/${day}a.c
	echo "$CONTENTS" > ${day}/${day}b.c
	echo "CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g

all: ${day}a ${day}b

${day}a: ${day}a.o
	\${CC} \${CFLAGS} -o \$@ ${day}a.c

${day}b: ${day}b.o
	\${CC} \${CFLAGS} -o \$@ ${day}b.c

.PHONY: clean

clean:
	rm ${day}a.o ${day}a ${day}b.o ${day}b" > ${day}/Makefile
done

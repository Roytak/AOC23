
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define NROWS 5
// #define NCOLS 5
#define NROWS 140
#define NCOLS 140

int steps[NROWS][NCOLS];
char array[NROWS][NCOLS];

void
evaluate(int pX, int pY, int ns, int x, int y)
{
	if (array[x][y] == 'S') {
		return;
	}

	if (!steps[x][y]) {
		steps[x][y] = ns + 1;
	} else {
		steps[x][y] = steps[x][y] < (ns + 1) ? steps[x][y] : (ns + 1);
	}

	switch (array[x][y]) {
	case '|':
		if (pX == x + 1) {
			evaluate(x, y, ns + 1,  x - 1, y);
		} else {
			evaluate(x, y, ns + 1, x + 1, y);
		}
		break;
	case '-':
		if (pY == y - 1) {
			// left to right
			evaluate(x, y, ns + 1, x, y + 1);
		} else {
			evaluate(x, y, ns + 1, x, y - 1);
		}
		break;
	case 'L':
		if (pX == x - 1) {
			evaluate(x, y, ns + 1, x, y + 1);
		} else {
			evaluate(x, y, ns + 1, x - 1, y);
		}
		break;
	case 'J':
		if (pX == x - 1) {
			evaluate(x, y, ns + 1, x, y - 1);
		} else {
			evaluate(x, y, ns + 1, x - 1, y);
		}
		break;
	case '7':
		if (pY == y - 1) {
			evaluate(x, y, ns + 1, x + 1, y);
		} else {
			evaluate(x, y, ns + 1, x, y - 1);
		}
		break;
	case 'F':
		if (pY == y + 1) {
			evaluate(x, y, ns + 1, x + 1,  y);
		} else {
			evaluate(x, y, ns + 1, x, y + 1);
		}
		break;
	default:
		break;
	}
}

int
main(void)
{
	FILE *f = fopen("in.txt", "r");
	int i, j, Sx, Sy;
	int c, max = 0;

	i = 0;
	while (fgets(array[i], NCOLS + 1, f)) {
		i++;
		while(1) {
			c = fgetc(f);
			if ((c == '\n') || (c == EOF)) {
				break;
			}
		}
	}

	for (i = 0; i < NROWS; i++) {
		for (j = 0; j < NCOLS; j++) {
			if (array[i][j] == 'S') {
				Sx = i;
				Sy = j;
				break;
			}
		}
	}

	// down
	if ((array[Sx + 1][Sy] == '|') || (array[Sx + 1][Sy] == 'J') || (array[Sx + 1][Sy] == 'L')) {
		evaluate(Sx, Sy, 0, Sx + 1, Sy);
	}
	// right
	if ((array[Sx][Sy + 1] == '-') || (array[Sx][Sy + 1] == '7') || (array[Sx][Sy + 1] == 'J')) {
		evaluate(Sx, Sy, 0, Sx, Sy + 1);
	}
	// up
	if ((array[Sx - 1][Sy] == '|') || (array[Sx - 1][Sy] == 'F') || (array[Sx - 1][Sy] == '7')) {
		evaluate(Sx, Sy, 0, Sx - 1, Sy);
	}
	// left
	if ((array[Sx][Sy - 1] == '-') || (array[Sx][Sy - 1] == 'L') || (array[Sx][Sy - 1] == 'F')) {
		evaluate(Sx, Sy, 0, Sx, Sy - 1);
	}

	for (i = 0; i < NROWS; i++) {
		for (j = 0; j < NCOLS; j++) {
			printf("%d", steps[i][j]);
			if (steps[i][j] > max) {
				max = steps[i][j];
			}
		}
		printf("\n");
	}
	printf("%d\n", max);

	return 0;
}



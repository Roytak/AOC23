
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int i, j, Sx, Sy, k, l;
    int c, max = 0;
    int sum = 0;

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

    int left = 0, right = 0;
    int have_F = 0, have_L = 0;
    for (i = 1; i < NROWS - 1; i++) {
        for (j = 1; j < NCOLS - 1; j++) {
            if (steps[i][j] || (array[i][j] == 'S')) {
                continue;
            }

            left = right = 0;
            for (k = 0; k < j; k++) {
                if (!steps[i][k]) {
                    continue;
                }
                switch (array[i][k]) {
                case '|':
                    left++;
                    have_F = 0;
                    have_L = 0;
                    break;
                case 'F':
                    have_F = 1;
                    have_L = 0;
                    break;
                case 'J':
                    if (have_F) {
                        left++;
                    }
                    have_F = 0;
                    have_L = 0;
                    break;
                case 'L':
                    have_L = 1;
                    have_F = 0;
                    break;
                case '7':
                    if (have_L) {
                        left++;
                    }
                    have_L = 0;
                    have_F = 0;
                    break;
                default:
                    break;
                }
            }
            for (l = j; l < NCOLS; l++) {
                if (!steps[i][l]) {
                    continue;
                }
                switch (array[i][l]) {
                case '|':
                    right++;
                    have_F = 0;
                    have_L = 0;
                    break;
                case 'F':
                    have_F = 1;
                    have_L = 0;
                    break;
                case 'J':
                    if (have_F) {
                        right++;
                    }
                    have_F = 0;
                    have_L = 0;
                    break;
                case 'L':
                    have_L = 1;
                    have_F = 0;
                    break;
                case '7':
                    if (have_L) {
                        right++;
                    }
                    have_L = 0;
                    have_F = 0;
                    break;
                default:
                    break;
                }
            }
            if ((left % 2) && (right % 2)) {
                sum++;
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}



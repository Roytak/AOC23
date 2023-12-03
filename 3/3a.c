#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct number {
    int value;

    int xs[10];
    int nx;
    int y;
};

struct point {
    int x;
    int y;
};

int sum = 0;
struct point symbols[1000] = {0};
int nsymbols = 0;

int
is_adj(struct number n)
{
    int i, j;

    for (i = 0; i < nsymbols; i++) {
        if (symbols[i].y == n.y) {
            /* same row */
            if (symbols[i].x == n.xs[0] - 1 || symbols[i].x == n.xs[n.nx - 1] + 1) {
                return 1;
            }
        } else if ((symbols[i].y == (n.y - 1)) || (symbols[i].y == (n.y + 1))) {
            /* symbol below */
            for (j = 0; j < n.nx; j++) {
                if ((n.xs[j] == symbols[i].x) || (n.xs[j] == (symbols[i].x + 1)) || (n.xs[j] == (symbols[i].x - 1))) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int
parse_line(char *line, int y, int *idx)
{
    int i, j;
    char number[10] = {0};
    struct number n = {0};

    n.y = y;
    for (i = *idx; line[i]; i++) {
        if (!isdigit(line[i])) {
            continue;
        }
        j = 0;
        while (isdigit(line[i])) {
            n.xs[j] = i;
            n.nx++;
            number[j++] = line[i++];
        }
        n.value = atoi(number);
        if (is_adj(n)) {
            sum += n.value;
        }
        break;
    }

    if (line[i]) {
        *idx = i;
        return 0;
    }
    return 1;
}

void
fill_symbols(FILE *f)
{
    char line[1024] = {0};
    int i, nl = 0;

    while (fgets(line, 1024, f)) {
        for (i = 0; line[i]; i++) {
            if (!isdigit(line[i]) && (line[i] != '.') && (line[i] != '\n')) {
                symbols[nsymbols].x = i;
                symbols[nsymbols].y = nl;
                nsymbols++;
            }
        }
        nl++;
    }

    rewind(f);
}

int
main(void)
{
    FILE *f = fopen("in.txt", "r");
    char line[1024] = {0};
    int idx, nl = 0;

    fill_symbols(f);

    while (fgets(line, 1024, f)) {
        idx = 0;
        while (!parse_line(line, nl, &idx));
        nl++;
    }

    printf("%d\n", sum);
    return 0;
}



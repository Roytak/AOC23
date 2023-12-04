#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HAVE_CARDS 10
#define WIN_CARDS 25

struct card {
	int have[HAVE_CARDS];
	int winning[WIN_CARDS];

	int worth;
};

int
cmp_int(const void *int1, const void *int2)
{
	int n1 = (*(int *) int1);
	int n2 = (*(int *) int2);

	if (n1 < n2) {
		return -1;
	} else if (n1 > n2) {
		return 1;
	} else {
		return 0;
	}
}

void
sort(struct card *cards, int ncards)
{
	int i;

	for (i = 0; i < ncards; i++) {
		qsort(cards[i].have, HAVE_CARDS, sizeof(int), cmp_int);
		qsort(cards[i].winning, WIN_CARDS, sizeof(int), cmp_int);
	}
}

void
increase_worth(struct card *card)
{
	if (card->worth == 0) {
		card->worth = 1;
	} else {
		card->worth <<= 1;
	}
}

void
get_worth(struct card *cards, int ncards)
{
	int i, j, k;

	for (i = 0; i < ncards; i++) {
		for (j = 0; j < HAVE_CARDS; j++) {
			k = 0;
			while (cards[i].have[j] > cards[i].winning[k]) {
				k++;
				if (k > WIN_CARDS) {
					break;
				}
			}
			if (cards[i].have[j] == cards[i].winning[k]) {
				increase_worth(&cards[i]);
			}
		}
	}
}

int
main(void)
{
	FILE *f = fopen("in.txt", "r");
	struct card cards[220] = {0};
	int ncards, i, sum;
	char line[1024] = {0};
	char *have, *win;

	/* parse input */
	ncards = 0;
	while (fgets(line, 1024, f)) {
		have = strchr(line, ':');
		have++;
		for (i = 0; i < HAVE_CARDS; i++) {
			while (!isdigit(*have)) {
				have++;
			}
			sscanf(have, "%d", &cards[ncards].have[i]);
			while (isdigit(*have)) {
				have++;
			}
		}
		win = strchr(line, '|');
		win++;
		for (i = 0; i < WIN_CARDS; i++) {
			while (!isdigit(*win)) {
				win++;
			}
			sscanf(win, "%d", &cards[ncards].winning[i]);
			while (isdigit(*win)) {
				win++;
			}
		}
		ncards++;
	}

	/* sort */
	sort(cards, ncards);

	get_worth(cards, ncards);

	sum = 0;
	for (i = 0; i < ncards; i++) {
		sum += cards[i].worth;
	}

	printf("%d\n", sum);

	fclose(f);
	return 0;
}



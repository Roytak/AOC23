#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int
check_cubes(int n, char *color)
{
	if (!strncmp(color, "blue", strlen("blue"))) {
		if (n > MAX_BLUE) {
			return 1;
		}
	} else if (!strncmp(color, "red", strlen("red"))) {
		if (n > MAX_RED) {
			return 1;
		}
	} else {
		if (n > MAX_GREEN) {
			return 1;
		}
	}

	return 0;
}

int
parse_line(char *line)
{
	int i, n = 0;
	int n1, n2, n3;
	char *token;
	char c1[10] = {0}, c2[10] = {0}, c3[10] = {0};

	line += 5;
	while (isdigit(*line)) {
		line++;
	}
	line++;

	while ((token = strtok(line, ";"))) {
		/* count the , */
		for (i = 0; token[i]; i++) {
			if (token[i] == ',') {
				n++;
			}
		}

		if (n == 0) {
			sscanf(token, "%d %s", &n1, c1);
			if (check_cubes(n1, c1)) {
				return 1;
			}
		} else if (n == 1) {
			sscanf(token, "%d %s %d %s", &n1, c1, &n2, c2);
			if (check_cubes(n1, c1) || check_cubes(n2, c2)) {
				return 1;
			}
		} else {
			sscanf(token, "%d %s %d %s %d %s", &n1, c1, &n2, c2, &n3, c3);
			if (check_cubes(n1, c1) || check_cubes(n2, c2) || check_cubes(n3, c3)) {
				return 1;
			}
		}

		n = 0;
		line = NULL;
	}

	return 0;
}

int
main(void)
{
	char buf[512] = {0};
	FILE *f = fopen("in.txt", "r");
	int sum = 0, i = 1;

	while(fgets(buf, 512, f)) {
		if (!parse_line(buf)) {
			sum += i;
		}
		i++;
	}

	printf("%d\n", sum);

	return 0;
}



#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int blue_min, red_min, green_min;

int
check_cubes(int n, char *color)
{
	if (!strncmp(color, "blue", strlen("blue"))) {
		if (n > blue_min) {
			blue_min = n;
		}
	} else if (!strncmp(color, "red", strlen("red"))) {
		if (n > red_min) {
			red_min = n;
		}
	} else {
		if (n > green_min) {
			green_min = n;
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

		line = NULL;
		n = 0;
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
		printf("%s", buf);
		parse_line(buf);
		sum += (red_min * blue_min * green_min);
		red_min = 0;
		blue_min = 0;
		green_min = 0;
		i++;
	}

	printf("%d\n", sum);

	return 0;
}

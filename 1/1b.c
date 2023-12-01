#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *str_digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", NULL};

int
get_digit(char *str)
{
	int i;

	if (*str >= '0' && *str <= '9') {
		return *str - '0';
	}

	for (i = 0; str_digits[i]; i++) {
		if (!strncmp(str, str_digits[i], strlen(str_digits[i]))) {
			return i + 1;
		}
	}

	return -1;
}

int
main(void)
{
	FILE *f = fopen("in.txt", "r");
	char buf[1024] = {0};
	int first, second, sum = 0;
	char *ptr;

	while (fgets(buf, 1024, f)) {
		ptr = buf;
		while ((first = get_digit(ptr)) == -1) {
			ptr++;
		}

		ptr = buf + strlen(buf) - 1;
		while ((second = get_digit(ptr)) == -1) {
			ptr--;
		}

		sum += (first * 10) + second;
	}
	printf("%d\n", sum);

	fclose(f);
	return 0;
}

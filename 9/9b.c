
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NINPUTS 21

int
parse(int *input, int size)
{
	int next[NINPUTS];
	int i;

	/* check if we should end */
	for (i = 0; i < size; i++) {
		if (input[i]) {
			break;
		}
	}
	if (i == size) {
		return 0;
	}

	/* create the next array */
	for (i = 0; i < size - 1; i++) {
		next[i] = input[i + 1] - input[i];
	}

	return input[0] - parse(next, size - 1);
}

int
main(void)
{
	FILE *f = fopen("in.txt", "r");
	int input[NINPUTS];
	int i, sum = 0;
	char line[512] = {0};
	char *ptr;

	while (fgets(line, 512, f)) {
		ptr = line;
		for (i = 0; i < NINPUTS; i++) {
			sscanf(ptr, "%d", &input[i]);

			while (*ptr != '\0' && (*ptr < '0' || *ptr > '9')) {
                ptr++;
            }

            while (*ptr != '\0' && *ptr >= '0' && *ptr <= '9') {
                ptr++;
            }
		}

		sum += parse(input, NINPUTS);
		memset(line, 0, 512);
	}

	printf("%d\n", sum);
	return 0;
}

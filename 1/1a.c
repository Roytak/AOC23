#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
	FILE *f = fopen("in.txt", "r");
	char buf[1024] = {0};
	int i, j, first, second, sum = 0;
	size_t len;

	while (fgets(buf, 1024, f)) {
		len = strlen(buf);
		for (i = 0; i < len; i++) {
			if (buf[i] >= '0' && buf[i] <= '9') {
				first = buf[i] - '0';
				break;
			}
		}
		for (j = len; j >= 0; j--) {
			if (buf[j] >= '0' && buf[j] <= '9') {
				second = buf[j] - '0';
				break;
			}
		}

		sum += (first * 10) + second;
	}

	printf("%d\n", sum);

	fclose(f);
	return 0;
}


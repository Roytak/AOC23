
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
calc_record_beat(unsigned long long time, unsigned long long distance)
{
	unsigned long long v, t, s, sum = 0;

	for (v = 1; v < time; v++) {
		t = time - v;
		s = v * t;
		if (s > distance) {
			sum++;
		}
	}

	return sum;
}

int
main(void)
{
	unsigned long long sum = 0;

	sum = calc_record_beat(59707878ULL, 430121812131276ULL);

	printf("%llu\n", sum);

	return 0;
}

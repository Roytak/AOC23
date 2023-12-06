
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define NINPUTS 3
#define NINPUTS 4

int
calc_record_beat(int time, int distance)
{
	int v, t, s, sum = 0;

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
	FILE *f = fopen("in.txt", "r");
	int times[NINPUTS];
	int distances[NINPUTS];
	char line[256];
	int sum = 1, record_beaten;

	fgets(line, 256, f);
	if (NINPUTS == 3) {
		sscanf(line, "Time: %d %d %d", &times[0], &times[1], &times[2]);
	} else {
		sscanf(line, "Time: %d %d %d %d", &times[0], &times[1], &times[2], &times[3]);
	}
	fgets(line, 256, f);
	if (NINPUTS == 3) {
		sscanf(line, "Distance: %d %d %d", &distances[0], &distances[1], &distances[2]);
	} else {
		sscanf(line, "Distance: %d %d %d %d", &distances[0], &distances[1], &distances[2], &distances[3]);
	}

	for (int i = 0; i < NINPUTS; i++) {
		record_beaten = calc_record_beat(times[i], distances[i]);
		if (record_beaten) {
			sum *= record_beaten;
		}
	}

	printf("%d\n", sum);

	fclose(f);
	return 0;
}



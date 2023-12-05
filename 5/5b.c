#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>

// #define NSEEDS 2
// #define NSOILS 2
// #define NFERTS 3
// #define NWATERS 4
// #define NLIGHTS 2
// #define NTEMPS 3
// #define NHUMIDS 2
// #define NLOCS 2

#define NSEEDS 10
#define NSOILS 16
#define NFERTS 13
#define NWATERS 22
#define NLIGHTS 46
#define NTEMPS 26
#define NHUMIDS 22
#define NLOCS 47

typedef enum {
    SEEDS,
    SOIL,
    FERTILIZER,
    WATER,
    LIGHT,
    TEMP,
    HUMIDITY,
    LOCATION
} current_source;

struct seed {
    uint32_t seed;
    uint32_t range;
};

struct pathing {
    uint32_t dest;
    uint32_t source;
    uint32_t range;
};

struct path {
    uint32_t seed;
    uint32_t soil;
    uint32_t fertilizer;
    uint32_t water;
    uint32_t light;
    uint32_t temp;
    uint32_t humidity;
    uint32_t location;
};

struct pathing soils[NSOILS] = {0};
struct pathing ferts[NFERTS] = {0};
struct pathing water[NWATERS] = {0};
struct pathing light[NLIGHTS] = {0};
struct pathing temps[NTEMPS] = {0};
struct pathing humids[NHUMIDS] = {0};
struct pathing locs[NLOCS] = {0};
struct seed seeds[NSEEDS] = {0};

uint32_t mins[NSEEDS];

int
get_new_source(current_source old)
{
    switch (old) {
    case SEEDS:
        return SOIL;
    case SOIL:
        return FERTILIZER;
    case FERTILIZER:
        return WATER;
    case WATER:
        return LIGHT;
    case LIGHT:
        return TEMP;
    case TEMP:
        return HUMIDITY;
    case HUMIDITY:
        return LOCATION;
    case LOCATION:
    default:
        return LOCATION;
    }
}

void
map_src_to_dest(uint32_t dest, uint32_t source, uint32_t range, uint32_t *old, uint32_t *new)
{
    if (*old >= source && (*old < (source + range))) {
        *new = *old - source + dest;
    }
}

void *
calculate_seed(void *arg)
{
    int i = (*(int *) arg);
    uint32_t min = UINT_MAX, max, j, k;
    struct path path = {0};

    max = seeds[i].seed + seeds[i].range;
    for (j = seeds[i].seed; j < max; j++) {
        path.seed = j;
        for (k = 0; k < NSOILS; k++) {
            map_src_to_dest(soils[k].dest, soils[k].source, soils[k].range, &path.seed, &path.soil);
        }
        if (!path.soil) {
            path.soil = path.seed;
        }
        for (k = 0; k < NFERTS; k++) {
            map_src_to_dest(ferts[k].dest, ferts[k].source, ferts[k].range, &path.soil, &path.fertilizer);
        }
        if (!path.fertilizer) {
            path.fertilizer = path.soil;
        }
        for (k = 0; k < NWATERS; k++) {
            map_src_to_dest(water[k].dest, water[k].source, water[k].range, &path.fertilizer, &path.water);
        }
        if (!path.water) {
            path.water = path.fertilizer;
        }
        for (k = 0; k < NLIGHTS; k++) {
            map_src_to_dest(light[k].dest, light[k].source, light[k].range, &path.water, &path.light);
        }
        if (!path.light) {
            path.light = path.water;
        }
        for (k = 0; k < NTEMPS; k++) {
            map_src_to_dest(temps[k].dest, temps[k].source, temps[k].range, &path.light, &path.temp);
        }
        if (!path.temp) {
            path.temp = path.light;
        }
        for (k = 0; k < NHUMIDS; k++) {
            map_src_to_dest(humids[k].dest, humids[k].source, humids[k].range, &path.temp, &path.humidity);
        }
        if (!path.humidity) {
            path.humidity = path.temp;
        }
        for (k = 0; k < NLOCS; k++) {
            map_src_to_dest(locs[k].dest, locs[k].source, locs[k].range, &path.humidity, &path.location);
        }
        if (!path.location) {
            path.location = path.humidity;
        }
        if (path.location < min) {
            min = path.location;
            printf("Thread %d new min: %u\n", i, min);
        }
        memset(&path, 0, sizeof path);
    }

    mins[i] = min;
    return NULL;
}

int
main(void)
{
    FILE *f = fopen("in.txt", "r");
    char line[1024] = {0};
    current_source current_source = SEEDS;
    int i;
    uint32_t min = UINT_MAX;
    int have_seeds = 0;

    while (fgets(line, 1024, f)) {
        if (!have_seeds) {
            if (NSEEDS == 2) {
                sscanf(line, "seeds: %u %u %u %u", &seeds[0].seed, &seeds[0].range, &seeds[1].seed, &seeds[1].range);
            } else {
                sscanf(line, "seeds: %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u", &seeds[0].seed, &seeds[0].range, &seeds[1].seed, &seeds[1].range, &seeds[2].seed, &seeds[2].range, &seeds[3].seed, &seeds[3].range, &seeds[4].seed, &seeds[4].range,
                    &seeds[5].seed, &seeds[5].range, &seeds[6].seed, &seeds[6].range, &seeds[7].seed, &seeds[7].range, &seeds[8].seed, &seeds[8].range, &seeds[9].seed, &seeds[9].range);
            }
            have_seeds = 1;
            continue;
        }

        if (line[0] == '\n' || line[0] == '\r') {
            continue;
        } else if (!isdigit(line[0])) {
            current_source = get_new_source(current_source);
            continue;
        }

        if (current_source == SOIL) {
            for (i = 0; i < NSOILS; i++) {
                sscanf(line, "%u %u %u", &soils[i].dest, &soils[i].source, &soils[i].range);
                fgets(line, 1024, f);
            }
        } else if (current_source == FERTILIZER) {
            for (i = 0; i < NFERTS; i++) {
                sscanf(line, "%u %u %u", &ferts[i].dest, &ferts[i].source, &ferts[i].range);
                fgets(line, 1024, f);
            }
        } else if (current_source == WATER) {
            for (i = 0; i < NWATERS; i++) {
                sscanf(line, "%u %u %u", &water[i].dest, &water[i].source, &water[i].range);
                fgets(line, 1024, f);
            }
        } else if (current_source == LIGHT) {
            for (i = 0; i < NLIGHTS; i++) {
                sscanf(line, "%u %u %u", &light[i].dest, &light[i].source, &light[i].range);
                fgets(line, 1024, f);
            }
        } else if (current_source == TEMP) {
            for (i = 0; i < NTEMPS; i++) {
                sscanf(line, "%u %u %u", &temps[i].dest, &temps[i].source, &temps[i].range);
                fgets(line, 1024, f);
            }
        } else if (current_source == HUMIDITY) {
            for (i = 0; i < NHUMIDS; i++) {
                sscanf(line, "%u %u %u", &humids[i].dest, &humids[i].source, &humids[i].range);
                fgets(line, 1024, f);
            }
        } else if (current_source == LOCATION) {
            for (i = 0; i < NLOCS; i++) {
                sscanf(line, "%u %u %u", &locs[i].dest, &locs[i].source, &locs[i].range);
                fgets(line, 1024, f);
            }
            break;
        }
    }

    pthread_t tids[NSEEDS];
    for (i = 0; i < NSEEDS; i++) {
        int *x = malloc(sizeof *x);
        *x = i;
        pthread_create(&tids[i], NULL, calculate_seed, x);
    }
    for (i = 0; i < NSEEDS; i++) {
        pthread_join(tids[i], NULL);
    }
    for (i = 0; i < NSEEDS; i++) {
        if (mins[i] < min) {
            min = mins[i];
        }
    }

    printf("min %u\n", min);

    return 0;
}

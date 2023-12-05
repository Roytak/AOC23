#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NSEEDS 20

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

struct node {
    uint32_t value;
    struct node *next;
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

void
map_sources_to_old(struct path paths[NSEEDS], current_source current_source)
{
    int i;

    switch (current_source) {
    case SOIL:
        for (i = 0; i < NSEEDS; i++) {
            if (!paths[i].soil) {
                paths[i].soil = paths[i].seed;
            }
        }
        break;
    case FERTILIZER:
        for (i = 0; i < NSEEDS; i++) {
            if (!paths[i].fertilizer) {
                paths[i].fertilizer = paths[i].soil;
            }
        }
        break;
    case WATER:
        for (i = 0; i < NSEEDS; i++) {
            if (!paths[i].water) {
                paths[i].water = paths[i].fertilizer;
            }
        }
        break;
    case LIGHT:
        for (i = 0; i < NSEEDS; i++) {
            if (!paths[i].light) {
                paths[i].light = paths[i].water;
            }
        }
        break;
    case TEMP:
        for (i = 0; i < NSEEDS; i++) {
            if (!paths[i].temp) {
                paths[i].temp = paths[i].light;
            }
        }
        break;
    case HUMIDITY:
        for (i = 0; i < NSEEDS; i++) {
            if (!paths[i].humidity) {
                paths[i].humidity = paths[i].temp;
            }
        }
        break;
    case LOCATION:
        for (i = 0; i < NSEEDS; i++) {
            if (!paths[i].location) {
                paths[i].location = paths[i].humidity;
            }
        }
        break;
    default:
        break;
    }
}

int
main(void)
{
    FILE *f = fopen("in.txt", "r");
    char line[1024] = {0};
    struct path paths[NSEEDS] = {0};
    current_source current_source = SEEDS;
    int i;
    uint32_t dest, source, range, min = UINT_MAX;

    while (fgets(line, 1024, f)) {
        if (line[0] == '\n' || line[0] == '\r') {
            map_sources_to_old(paths, current_source);
            current_source = get_new_source(current_source);
            continue;
        } else if (!isdigit(line[0]) && current_source != SEEDS) {
            continue;
        }

        if (current_source == SEEDS) {
            if (NSEEDS == 4) {
                sscanf(line, "seeds: %u %u %u %u", &paths[0].seed, &paths[1].seed, &paths[2].seed, &paths[3].seed);
            } else {
                sscanf(line, "seeds: %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u", &paths[0].seed, &paths[1].seed, &paths[2].seed, &paths[3].seed, &paths[4].seed, &paths[5].seed, &paths[6].seed, &paths[7].seed, &paths[8].seed, &paths[9].seed,
                    &paths[10].seed, &paths[11].seed, &paths[12].seed, &paths[13].seed, &paths[14].seed, &paths[15].seed, &paths[16].seed, &paths[17].seed, &paths[18].seed, &paths[19].seed);
            }
        } else if (current_source == SOIL) {
            sscanf(line, "%u %u %u", &dest, &source, &range);
            for (i = 0; i < NSEEDS; i++) {
                map_src_to_dest(dest, source, range, &paths[i].seed, &paths[i].soil);
            }
        } else if (current_source == FERTILIZER) {
            sscanf(line, "%u %u %u", &dest, &source, &range);
            for (i = 0; i < NSEEDS; i++) {
                map_src_to_dest(dest, source, range, &paths[i].soil, &paths[i].fertilizer);
            }
        } else if (current_source == WATER) {
            sscanf(line, "%u %u %u", &dest, &source, &range);
            for (i = 0; i < NSEEDS; i++) {
                map_src_to_dest(dest, source, range, &paths[i].fertilizer, &paths[i].water);
            }
        } else if (current_source == LIGHT) {
            sscanf(line, "%u %u %u", &dest, &source, &range);
            for (i = 0; i < NSEEDS; i++) {
                map_src_to_dest(dest, source, range, &paths[i].water, &paths[i].light);
            }
        } else if (current_source == TEMP) {
            sscanf(line, "%u %u %u", &dest, &source, &range);
            for (i = 0; i < NSEEDS; i++) {
                map_src_to_dest(dest, source, range, &paths[i].light, &paths[i].temp);
            }
        } else if (current_source == HUMIDITY) {
            sscanf(line, "%u %u %u", &dest, &source, &range);
            for (i = 0; i < NSEEDS; i++) {
                map_src_to_dest(dest, source, range, &paths[i].temp, &paths[i].humidity);
            }
        } else if (current_source == LOCATION) {
            sscanf(line, "%u %u %u", &dest, &source, &range);
            for (i = 0; i < NSEEDS; i++) {
                map_src_to_dest(dest, source, range, &paths[i].humidity, &paths[i].location);
            }
        }
    }
    map_sources_to_old(paths, current_source);
    for (i = 0; i < NSEEDS; i++) {
        if (paths[i].location < min) {
            min = paths[i].location;
        }
        printf("seed %u soil %u fert %u water %u light %u temp %u humidity %u location %u\n", paths[i].seed, paths[i].soil, paths[i].fertilizer, paths[i].water, paths[i].light, paths[i].temp, paths[i].humidity, paths[i].location);
    }
    printf("min: %u\n", min);

    return 0;
}

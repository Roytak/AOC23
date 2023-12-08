
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[4];

    struct node *left;
    struct node *right;
};

char directions[512];
int current = 0;

struct node *
get_node_by_name(struct node *nodes, int nnodes, char *name)
{
    int i;

    for (i = 0; i < nnodes; i++) {
        if (!strcmp(nodes[i].name, name)) {
            return &nodes[i];
        }
    }

    return NULL;
}

char
get_direction()
{
    char d;

    d = directions[current];
    if ((d != 'L') && (d != 'R')) {
        current = 1;
        return directions[0];
    }
    current++;
    return d;
}

int
main(void)
{
    FILE *f = fopen("in.txt", "r");
    struct node *nodes = NULL;
    int nnodes = 0, i, sum = 0;
    char buffer[512] = {0}, left[4] = {0}, right[4] = {0};
    char *ptr;
    struct node *iter;
    char d;

    fgets(directions, 512, f);
    fgets(buffer, 512, f);

    while (fgets(buffer, 512, f)) {
        nodes = realloc(nodes, (nnodes + 1) * sizeof *nodes);
        sscanf(buffer, "%s", nodes[nnodes].name);
        nnodes++;
    }

    rewind(f);
    fgets(buffer, 512, f);
    fgets(buffer, 512, f);
    i = 0;
    while (fgets(buffer, 512, f)) {
        ptr = buffer + 6;
        sscanf(ptr, "(%3[^,], %3[^)])", left, right);
        nodes[i].left = get_node_by_name(nodes, nnodes, left);
        nodes[i].right = get_node_by_name(nodes, nnodes, right);
        i++;
    }

    iter = get_node_by_name(nodes, nnodes, "AAA");
    while (strcmp(iter->name, "ZZZ")) {
        d = get_direction();

        if (d == 'L') {
            iter = iter->left;
        } else {
            iter = iter->right;
        }
        sum++;
    }

    printf("%d\n", sum);

    return 0;
}



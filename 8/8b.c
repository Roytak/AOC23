
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[4];

    struct node *left;
    struct node *right;
};

struct end {
    int *steps;
    int nsteps;
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

// Function to find the GCD (Greatest Common Divisor)
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the LCM (Least Common Multiple)
unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return (a * b) / gcd(a, b);
}

int
main(void)
{
    FILE *f = fopen("in.txt", "r");
    struct node *nodes = NULL;
    int nnodes = 0, i;
    char buffer[512] = {0}, left[4] = {0}, right[4] = {0};
    char *ptr;
    struct node *iter1, *iter2, *iter3, *iter4, *iter5, *iter6;
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

    iter1 = iter2 = iter3 = iter4 = iter5 = iter6 = NULL;
    for (i = 0; i < nnodes; i++) {
        if (nodes[i].name[2] == 'A') {
            if (!iter1) {
                iter1 = &nodes[i];
            } else if (!iter2) {
                iter2 = &nodes[i];
            } else if (!iter3) {
                iter3 = &nodes[i];
            } else if (!iter4) {
                iter4 = &nodes[i];
            } else if (!iter5) {
                iter5 = &nodes[i];
            } else {
                iter6 = &nodes[i];
            }
        }
    }
    int one, two, three, four, five, six;
    int first = 0, second = 0;
    int match = 0;
    i = 0;
    while (1) {
        if (iter1->name[2] == 'Z') {
            if (!first) {
                first = i;
            } else {
                second = i;
                break;
            }
            match++;
        }
        d = get_direction();
        if (d == 'L') {
            iter1 = iter1->left;
        } else {
            iter1 = iter1->right;
        }
        i++;
        if (match == 8) {
            break;
        }
    }
    printf("\n");
    one = second - first;
    i = 0;
    first = second = 0;
    match = 0;
    current = 0;
    while (1) {
        if (iter2->name[2] == 'Z') {
            if (!first) {
                first = i;
            } else {
                second = i;
                break;
            }
            match++;
        }
        d = get_direction();
        if (d == 'L') {
            iter2 = iter2->left;
        } else {
            iter2 = iter2->right;
        }
        i++;
        if (match == 10) {
            break;
        }
    }
    printf("\n");
    two = second - first;
    i = 0;
    first = second = 0;
    match = 0;
    current = 0;
    while (1) {
        if (iter3->name[2] == 'Z') {
            if (!first) {
                first = i;
            } else {
                second = i;
                break;
            }
            match++;
        }
        d = get_direction();
        if (d == 'L') {
            iter3 = iter3->left;
        } else {
            iter3 = iter3->right;
        }
        i++;
        if (match == 10) {
            break;
        }
    }
    printf("\n");
    three = second - first;
    i = 0;
    first = second = 0;
    match = 0;
    current = 0;
    while (1) {
        if (iter4->name[2] == 'Z') {
            if (!first) {
                first = i;
            } else {
                second = i;
                break;
            }
            match++;
        }
        d = get_direction();
        if (d == 'L') {
            iter4 = iter4->left;
        } else {
            iter4 = iter4->right;
        }
        i++;
        if (match == 10) {
            break;
        }
    }
    printf("\n");
    four = second - first;
    i = 0;
    first = second = 0;
    match = 0;
    current = 0;
    while (1) {
        if (iter5->name[2] == 'Z') {
            if (!first) {
                first = i;
            } else {
                second = i;
                break;
            }
            match++;
        }
        d = get_direction();
        if (d == 'L') {
            iter5 = iter5->left;
        } else {
            iter5 = iter5->right;
        }
        i++;
        if (match == 10) {
            break;
        }
    }
    printf("\n");
    five = second - first;
    i = 0;
    first = second = 0;
    match = 0;
    current = 0;
    while (1) {
        if (iter6->name[2] == 'Z') {
            if (!first) {
                first = i;
            } else {
                second = i;
                break;
            }
            match++;
        }
        d = get_direction();
        if (d == 'L') {
            iter6 = iter6->left;
        } else {
            iter6 = iter6->right;
        }
        i++;
        if (match == 10) {
            break;
        }
    }
    six = second - first;

    unsigned long long ans;
    ans = lcm(one, two);
    ans = lcm(ans, three);
    ans = lcm(ans, four);
    ans = lcm(ans, five);
    ans = lcm(ans, six);

    printf("%llu\n", ans);

    return 0;
}

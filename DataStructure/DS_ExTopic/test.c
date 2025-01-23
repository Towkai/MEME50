#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Func/equation.h"

void main() {
    Item *node1_2 = new_Item(1, 2);
    Item *node1_1 = new_Item(1, 1);
    Item *node1_0 = new_Item(1, 0);
    Item *node2_0 = new_Item(2, 0);
    Item *node2_1 = new_Item(2, 1);
    Item *node2_2 = new_Item(2, 2);
    Item *node_void = {NULL};

    addpolynomial(node1_2, node1_1);
    // printf("[main]node1_2 =");
    // traverse(node1_2);
    addpolynomial(node2_2, node2_1);
    // printf("[main]node2_2 =");
    // traverse(node2_2);
    Item *result = (mulpolynomial(node1_2, node2_2));
    printf("[main]node1_2 =");
    traverse(node1_2);
    printf("[main]result =");
    traverse(result);
    printf("[main]exit");
}

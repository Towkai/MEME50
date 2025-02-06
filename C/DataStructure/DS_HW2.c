#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../myheaders/equation.h"

void main() {
    Item *node1_2 = new_Item(5, 2);
    Item *node1_1 = new_Item(6, 1);
    Item *node1_0 = new_Item(7, 0);
    Item *node2_2 = new_Item(3, 2);
    Item *node2_1 = new_Item(2, 1);
    Item *node2_0 = new_Item(1, 0);
    Item *node_void = {NULL};

    addpolynomial(node1_2, node1_2);
    addpolynomial(node1_2, node1_1);
    addpolynomial(node1_2, node1_0);
    // printf("[main]node1_2 =");
    // traverse(node1_2);
    addpolynomial(node2_2, node2_2);
    addpolynomial(node2_2, node2_1);
    addpolynomial(node2_2, node2_0);
    // printf("[main]node2_2 =");
    // traverse(node2_2);

    printf("多項式相乘\n");
    printf("(");
    traverse(node1_2);
    printf(")");
    printf(" * ");
    printf("(");
    traverse(node2_2);
    printf(") = ");

    Item *result = (mulpolynomial(node1_2, node2_2));
    traverse(result);
}


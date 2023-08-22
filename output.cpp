#include "square_solver.h"
#include <stdio.h>

void output(int nRoots, double x1, double x2) {
    switch(nRoots) {
    case NO_ROOTS: printf("No roots\n");
            break;

    case ONE_ROOT: printf("1 root\nx = %lg\n", x1);
            break;

    case TWO_ROOTS: printf("2 roots\nx1 = %lg\nx2 = %lg\n", x1, x2);
            break;

    case INF_ROOTS: printf("Any number\n");
                    break;

    default: printf("main(): ERROR: nRoots = %d\n", nRoots);
             break;

    }
}

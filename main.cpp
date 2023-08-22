#include "square_solver.h"
#include "eq_solvers.cpp"
#include "output.cpp"
#include <stdio.h>

// TODO: "" vs <> (include)


// TODO: multiple cpp files
// TODO: headers, rename file, main.cpp

int main() {
    printf("# Square solver\n");
    printf("# Solves the equation ax^2 + bx + c = 0\n\n");
    printf("Enter a, b, c: ");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c); // TODO: check input

    printf("Your koeffs are:\na = %lg, b = %lg, c = %lg\n", a, b, c);

    double x1 = 0, x2 = 0;
    int nRoots = solveSquare(a, b, c, &x1, &x2);

    output(nRoots, x1, x2);
}

#include <stdio.h>
#include <math.h>
#include <assert.h>

// TODO: "" vs <> (include)

const double EPSILON = 0.000001;

enum NUMBERS_OF_ROOTS  {NO_ROOTS = 0, ONE_ROOT,
                        TWO_ROOTS, INF_ROOTS};


// TODO: multiple cpp files
// TODO: headers, rename file, main.cpp


bool isZero (double number);
int solveLinear(const double a, const double b,
                    double* x1);
int solveSquare(const  double a, const double b,
                const double c, double* x1, double* x2);
void output(int nRoots, double x1, double x2);


bool isZero (double number) {
    if (number < 0) number = -number;
    if (number < EPSILON) return true;
    return false;
}

int solveLinear(const double a, const double b, double* x1) {

    assert(isfinite(a));
    assert(isfinite(b));

    assert(x1 != NULL);

    if (isZero(a)) return isZero(b) ? INF_ROOTS : NO_ROOTS;
    *x1 = - b / a;
    return ONE_ROOT;
}

int solveSquare(const  double a, const double b,
                const double c, double* x1, double* x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (isZero(a)) {
        if (isZero(b)) return isZero(c) ? INF_ROOTS : NO_ROOTS;

        return solveLinear(b, c, x1);
    }

    double D = b*b - 4*a*c;
    if (D < 0) return NO_ROOTS;

    if (D > 0) {
        double sqD = sqrt(D);
        *x1 = (-b + sqD) / 2 / a;
        *x2 = (-b - sqD) / 2 / a;
        return TWO_ROOTS;
    }

    *x1 = -b / 2 / a;
    return ONE_ROOT;
}

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

int main() {
    printf("# Square solver\n");
    printf("# Solves the equation ax^2 + bx + c = 0\n\n");
    printf("Enter a, b, c: ");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c); // TODO: check input

    printf("%lg %lg %lg\n", a, b, c);

    double x1 = 0, x2 = 0;
    int nRoots = solveSquare(a, b, c, &x1, &x2);

    output(nRoots, x1, x2);
}

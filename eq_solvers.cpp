#include "square_solver.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>


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

#ifndef __SQUARE_SOLVER_H__
#define __SQUARE_SOLVER_H__

const double EPSILON = 0.000001;

enum NUMBERS_OF_ROOTS  {NO_ROOTS = 0, ONE_ROOT,
                        TWO_ROOTS, INF_ROOTS};

bool isZero (double number);

int solveLinear(const double a, const double b,
                    double* x1);

int solveSquare(const  double a, const double b,
                const double c, double* x1, double* x2);

void output(int nRoots, double x1, double x2);

#endif //__SQUARE_SOLVER_H__

#include <stdio.h>
#include <Accelerate/Accelerate.h>
#include "linAlg.h"
#include <complex.h>
int main() {
    int n = 3; // Size of the system

    // Real number system of equations
    __CLPK_doublereal A[] = {1.0, 6.0, 5.0, 
                            1.0, -4.0, 2.0, 
                            1.0, 5.0, 2.0
                            }; // Matrix A in column-major order
    __CLPK_doublereal b[] = {2.0, 31.0, 13.0}; // Right-hand side vector

    // Complex number system of equations
    __CLPK_doublecomplex AComp[] = {
       (1.0), (2.0), (3.0),
        (0.0), (1.0 + 3.0*I), (2.0 + 2.0*I),
        (2.0), (0.0 + 2.0*I), (1.0 - 3.0*I)
    };
    __CLPK_doublecomplex bComp[] = {(-1.0 - 1.0*I), (2.0*I), (-1.0 + 1.0*I)};

    // Solve real number system of equations
    solveSystemOfEquations(A, b, n);
    
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i, b[i]);
    }
    solveSystemOfComplexEquations(AComp,bComp,n);

    printf("\n");
    // Solve complex number system of equations
   for (int i = 0; i < n; i++) {
  printf("complex_X[%d] = (%.2f+ %.2fj)\n", i, bComp[i].r, bComp[i].i);

    }

    return 0;
}

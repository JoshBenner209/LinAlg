/*  
    Josh Benner
    08/07/2023
    
    Using Apples Acclerate Frame work to solve System of Equations.
    
    Important note: The Orignal Matrices get overwritten:
        In the equation AX=b
        -A is overwritten with LU decomposition
        -b is input and also used for the output of the solved system

*/

#ifndef linAlg
#define linAlg
#include <stdio.h>
#include <Accelerate/Accelerate.h>
#include <complex.h>
// Place your function prototypes, constants, and type declarations here

//Solves AX=b for x for real numbers only
// Matrix A (A is overwritten with LU decomposition)
// Right-hand side matrix bx (input and output)
void solveSystemOfEquations(double *A,  double *bx, int size ){
   int n = size;    // Number of equations (size of the square matrix A)
    int nrhs = 1;   // Number of right-hand sides (number of columns in B)
    int lda = size; // Leading dimension of A (spacing between rows in memory)
    int ldb = size; // Leading dimension of B (spacing between rows in memory)
    int ipiv[size];  // Pivot indices (output, used to track row interchanges)
    int info;       // Information flag (output, indicates success or failure)

    dgesv_(&n, &nrhs, A, &lda, ipiv, bx, &ldb, &info); // LAPACK Long-precision real
        
        if (info != 0) {
          printf("cgesv failed with error code %d\n", info);
        } 
}
void solveSystemOfComplexEquations(__CLPK_doublecomplex *A, __CLPK_doublecomplex *bx,int size){
  int n = size;    // Number of equations (size of the square matrix A)
    int nrhs = 1;   // Number of right-hand sides (number of columns in B)
    int lda = size; // Leading dimension of A (spacing between rows in memory)
    int ldb = size; // Leading dimension of B (spacing between rows in memory)
    int ipiv[size];  // Pivot indices (output, used to track row interchanges)
    int info;  
    zgesv_(&n, &nrhs, A, &lda, ipiv, bx, &ldb, &info); //Long-precision complex
        if (info != 0) {
          printf("zgesv failed with error code %d\n", info);
        } 

}
// Constants example
#define PI 3.14159265359

// Type declarations example


#endif // linAlg

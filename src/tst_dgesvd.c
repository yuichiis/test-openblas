/*******************************************************************************
*  Copyright (C) 2009-2015 Intel Corporation. All Rights Reserved.
*  The information and material ("Material") provided below is owned by Intel
*  Corporation or its suppliers or licensors, and title to such Material remains
*  with Intel Corporation or its suppliers or licensors. The Material contains
*  proprietary information of Intel or its suppliers and licensors. The Material
*  is protected by worldwide copyright laws and treaty provisions. No part of
*  the Material may be copied, reproduced, published, uploaded, posted,
*  transmitted, or distributed in any way without Intel's prior express written
*  permission. No license under any patent, copyright or other intellectual
*  property rights in the Material is granted to or conferred upon you, either
*  expressly, by implication, inducement, estoppel or otherwise. Any license
*  under such intellectual property rights must be express and approved by Intel
*  in writing.
*
********************************************************************************
*/
/*
    DGESVD Example.
    ==============
 
    Program computes the singular value decomposition of a general
    rectangular matrix A:
 
      8.79   9.93   9.83   5.45   3.16
      6.11   6.91   5.04  -0.27   7.98
     -9.15  -7.93   4.86   4.85   3.01
      9.57   1.64   8.83   0.74   5.80
     -3.49   4.02   9.80  10.00   4.27
      9.84   0.15  -8.99  -6.02  -5.31
 
    Description.
    ============
 
    The routine computes the singular value decomposition (SVD) of a real
    m-by-n matrix A, optionally computing the left and/or right singular
    vectors. The SVD is written as
 
    A = U*SIGMA*VT
 
    where SIGMA is an m-by-n matrix which is zero except for its min(m,n)
    diagonal elements, U is an m-by-m orthogonal matrix and VT (V transposed)
    is an n-by-n orthogonal matrix. The diagonal elements of SIGMA
    are the singular values of A; they are real and non-negative, and are
    returned in descending order. The first min(m, n) columns of U and V are
    the left and right singular vectors of A.
 
    Note that the routine returns VT, not V.
 
    Example Program Results.
    ========================

    DGESVD Example Program Results

    Singular values
     27.47  22.64   8.56   5.99   2.01

    Left singular vectors (stored columnwise)
     -0.59   0.26   0.36   0.31   0.23
     -0.40   0.24  -0.22  -0.75  -0.36
     -0.03  -0.60  -0.45   0.23  -0.31
     -0.43   0.24  -0.69   0.33   0.16
     -0.47  -0.35   0.39   0.16  -0.52
      0.29   0.58  -0.02   0.38  -0.65

    Right singular vectors (stored rowwise)
     -0.25  -0.40  -0.69  -0.37  -0.41
      0.81   0.36  -0.25  -0.37  -0.10
     -0.26   0.70  -0.22   0.39  -0.49
      0.40  -0.45   0.25   0.43  -0.62
     -0.22   0.14   0.59  -0.63  -0.44
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int lapack_int;
#define LAPACK_ROW_MAJOR               101
#define LAPACK_COL_MAJOR               102
#if defined(__APPLE__)
    #include <Accelerate/Accelerate.h>
    typedef __LAPACK_int lapack_int;
#else
    #ifndef _MSC_VER
        #define min(a, b) ((a) < (b) ? (a) : (b))
    #endif
    /* DGESVD prototype */
    extern void dgesvd_(
        char* jobu, char* jobvt, lapack_int* m, lapack_int* n, const double* a,
        lapack_int* lda, double* s, double* u, lapack_int* ldu, double* vt, lapack_int* ldvt,
        double* work, lapack_int* lwork, lapack_int* info );
#endif

/* Auxiliary routines prototypes */
void print_matrix( int matrix_layout, char* desc, lapack_int m, lapack_int n, double* a, lapack_int lda );

lapack_int E_dgesvd(
    int matrix_layout,
    char jobu, char jobvt,
    lapack_int m, lapack_int n,
    const double* a,  lapack_int lda,
    double* s,
    double* u,  lapack_int ldu,
    double* vt, lapack_int ldvt,
    double* superb
) {
    double wkopt = 0;
    double* work = NULL;
    lapack_int lwork = -1;
    lapack_int info  = 0;
    char jobu4[4] = {0,0,0,0};
    char jobvt4[4] = {0,0,0,0};
    jobu4[0] = jobu;
    jobvt4[0] = jobvt;
    double* targetA;
    double* targetU;
    double* targetVT;
    double* buffA = NULL;
    double* buffU = NULL;
    double* buffVT = NULL;

    if(matrix_layout==LAPACK_ROW_MAJOR) {
        printf("ROW_MAJOR\n");
        targetA = buffA = malloc( m*n*sizeof(double) );
        memcpy(targetA, a, m*n*sizeof(double) );
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                targetA[j*m+i] = a[i*n+j];
            }
        }
        targetU = buffU = malloc( m*m*sizeof(double) );
        targetVT = buffVT = malloc( n*n*sizeof(double) );
        memcpy(targetU,  u,  m*m*sizeof(double) );
        memcpy(targetVT, vt, n*n*sizeof(double) );
        lda = m;
    } else if(matrix_layout==LAPACK_COL_MAJOR) {
        printf("COL_MAJOR\n");
        targetA = (double *)a;
        targetU = u;
        targetVT = vt;
    } else {
        printf("Invalid matrix_layout: %d\n",matrix_layout);
        info = 1;
        goto final_E_dgesvd;
    }

    printf("AAAAAAAAAAAAAAAAAA\n");
    dgesvd_( jobu4, jobvt4, &m, &n, targetA, &lda, s, targetU, &ldu, targetVT, &ldvt, &wkopt, &lwork, &info);
    printf("BBBBBBBBBBBBBBBBBBB\n");
    if( info != 0 ) {
        goto final_E_dgesvd;
    }
    lwork = (int)wkopt;
    work = (double*)malloc( lwork*sizeof(double) );
    printf("CCCCCCCCCCCCCCCCCC\n");
    /* Compute SVD */
    dgesvd_( jobu4, jobvt4, &m, &n, targetA, &lda, s, targetU, &ldu, targetVT, &ldvt, work, &lwork, &info );
    printf("DDDDDDDDDDDDDDDDDD\n");
    if( info != 0 ) {
        goto final_E_dgesvd;
    }

    for(int i=0; i<min(m,n)-1; i++ ) {
        superb[i] = work[i+1];
    }
    if(matrix_layout==LAPACK_ROW_MAJOR) {
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                u[j*m+i] = targetU[i*m+j];
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                vt[j*n+i] = targetVT[i*n+j];
            }
        }
    }

final_E_dgesvd:
    if(work!=NULL) {
        free(work);
    }
    if(buffA!=NULL) {
        free(buffA);
    }
    if(buffU!=NULL) {
        free(buffU);
    }
    if(buffVT!=NULL) {
        free(buffVT);
    }
    return info;
}

/* Parameters */
#define M 6
#define N 5
#define LDA N
#define LDU M
#define LDVT N

///* Parameters */
//#define M 6
//#define N 5
//#define LDA M
//#define LDU M
//#define LDVT N


/* Main program */
int main() {
    /* Locals */
    lapack_int m = M, n = N, lda = LDA, ldu = LDU, ldvt = LDVT, info;
    //int lwork;
    int matrix_layout = LAPACK_ROW_MAJOR;
    //double wkopt;
    //double* work;
    /* Local arrays */
    double superb[M];
    double s[N], u[M*M], vt[N*N];
    double a[M*N] = {
         8.79,  9.93,  9.83,  5.45,  3.16,
         6.11,  6.91,  5.04, -0.27,  7.98,
        -9.15, -7.93,  4.86,  4.85,  3.01,
         9.57,  1.64,  8.83,  0.74,  5.80,
        -3.49,  4.02,  9.80, 10.00,  4.27,
         9.84,  0.15, -8.99, -6.02, -5.31
    };
    /* Executable statements */
    printf( " DGESVD Example Program Results\n" );
    /* Compute SVD */
    info = E_dgesvd( matrix_layout, 'A', 'A',
        m, n, a, lda, s, u, ldu, vt, ldvt, superb );
    printf("info=%d\n",info);
    if(info) {
        exit( 1 );
    }
    /* Print singular values */
    print_matrix( matrix_layout, "Singular values(s)", 1, n, s, 1 );
    /* Print left singular vectors */
    print_matrix( matrix_layout, "Left singular vectors(u) (stored columnwise)", m, m, u, ldu );
    /* Print right singular vectors */
    print_matrix( matrix_layout, "Right singular vectors(vt) (stored rowwise)", n, n, vt, ldvt );
    /* Free workspace */
    exit( 0 );
} /* End of DGESVD Example */

/* Auxiliary routine: printing a matrix */
void print_matrix( int matrix_layout, char* desc, int m, int n, double* a, int lda ) {
    int i, j;
    int ldm, ldn;
    if(matrix_layout==LAPACK_ROW_MAJOR) { ldm = lda; ldn = 1; }
    else                                { ldm = 1; ldn = lda; }
    //printf( "\n %s\n", desc );
    for( i = 0; i < m; i++ ) {
            for( j = 0; j < n; j++ ) printf( " %6.2lf", a[i*ldm+j*ldn] );
            //for( j = 0; j < n; j++ ) printf( " %le", a[i*ldm+j*ldn] );
            printf( "\n" );
    }
}


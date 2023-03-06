#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>
#include <string.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>

void test_info(int argc, char *argv[])
{
    printf("sizeof(blasint)=%zd bit\n",sizeof(blasint)*8);
    printf("sizeof(CBLAS_INDEX)=%zd bit\n",sizeof(CBLAS_INDEX)*8);
    printf("sizeof(lapack_int)=%zd bit\n",sizeof(lapack_int)*8);
    printf("sizeof(int)=%zd bit\n",sizeof(int)*8);
    printf("sizeof(long)=%zd bit\n",sizeof(long)*8);
    printf("sizeof(long long)=%zd bit\n",sizeof(long long)*8);
    printf("sizeof(size_t)=%zd bit\n",sizeof(size_t)*8);
    printf("threads=%d\n",openblas_get_num_threads());
    printf("procs=%d\n",openblas_get_num_procs());
    printf("config=%s\n",openblas_get_config());
    printf("corename=%s\n",openblas_get_corename());
    int para_mode = openblas_get_parallel();
    char *para_str;
    switch(para_mode) {
        case OPENBLAS_SEQUENTIAL: { para_str = "SEQUENTIAL"; break; } /* OpenBLAS is compiled for sequential use  */
        case OPENBLAS_THREAD:     { para_str = "THREAD"; break; }     /* OpenBLAS is compiled using normal threading model */
        case OPENBLAS_OPENMP:     { para_str = "OPENMP"; break; }     /* OpenBLAS is compiled using OpenMP threading model */
        default:                  { para_str = "UNKNOWN"; break; }
    }
    printf("parallel=%d(%s)\n",para_mode,para_str);
    printf("CblasNoTrans=%d\n",CblasNoTrans);
    printf("CblasTrans=%d\n",CblasTrans);
    printf("CblasConjTrans=%d\n",CblasConjTrans);
    printf("CblasConjNoTrans=%d\n",CblasConjNoTrans);
    printf("--\n");
    printf("\n");
}

void test_isamax(int argc, char *argv[])
{
    int i,j;
    int m=1;
    int n=20;
    int k=1;
    int incx=1;
    int incy=1;
    int lda=1;
    int ldb=1;
    int ldc=1;
    float *a,*b,*c,*x,*y;
    float alpha = 1.0;
    float beta =  0.0;

    if(argc>1)
        n=atoi(argv[1]);
    if(argc>2)
        incx=atoi(argv[2]);
    printf("n=%d,incx=%d\n",n,incx);

    //                 0     1     2     3     4     5     6     7     8     9
    float x1[20] = {  8.0, 59.0,  6.0, 57.0,  4.0, 55.0,  2.0, 53.0,  0.0, 51.0,
                     10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0};
    printf("isamax=x[%d*%d]=%f\n",(int)cblas_isamax(n, x1, incx),incx,x1[(int)cblas_isamax(n, x1, incx)*incx]);
    printf("isamin=x[%d*%d]=%f\n",(int)cblas_isamin(n, x1, incx),incx,x1[(int)cblas_isamin(n, x1, incx)*incx]);
    printf("--\n");
}

void test_sasum(int argc, char *argv[])
{
    int i,j;
    int m=1;
    int n=20;
    int k=1;
    int incx=1;
    int incy=1;
    int lda=1;
    int ldb=1;
    int ldc=1;
    float *a,*b,*c,*x,*y;
    float alpha = 1.0;
    float beta =  0.0;

    if(argc>1)
        n=atoi(argv[1]);
    if(argc>2)
        incx=atoi(argv[2]);
    printf("n=%d,incx=%d\n",n,incx);

    //                 0     1     2     3     4     5     6     7     8     9
    float x2[20] = {  1.0,  -1.0,  1.0,  -1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,
                     10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0};
    float x3[20] = {  1.0,  -1.0,  1.0,  -1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,
                     10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0};

    printf("sasum=%f\n",cblas_sasum(n, x2, incx));
    printf("ssum=%f\n", cblas_ssum( n, x3, incx));
    printf("--\n");
}

void test_sgemv(int argc, char *argv[])
{
    int i,j;
    int m=1;
    int n=20;
    int k=1;
    int incx=1;
    int incy=1;
    int lda=1;
    int ldb=1;
    int ldc=1;
    float *a,*b,*c,*x,*y;
    float alpha = 1.0;
    float beta =  0.0;

    if(argc>1)
        n=atoi(argv[1]);
    if(argc>2)
        incx=atoi(argv[2]);
    printf("n=%d,incx=%d\n",n,incx);


    //                 0     1     2     3     4     5     6     7     8     9
    float a3[12] = {  1.0,  0.0, 88.0, 88.0,
                      0.0,  1.0, 88.0, 88.0,
                      1.0,  1.0, 88.0, 88.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float x3[2] = {  1.0,   1.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float y3[20] = { 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0,
                     99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0 };
    m=3;
    n=2;
    incx = 1;
    incy = 1;
    lda = n*2;

    alpha = 1.0;
    a = a3;
    x = x3;
    beta =  0.0;
    y = y3;
    cblas_sgemv(CblasRowMajor, CblasNoTrans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("[");
    for(i=0;i<20;i++) {
        printf("%f,",y[i]);
    }
    printf("]\n");
}

void calc_sgemv_bufMax(
    float *y,
    int trans,int m, int n,
    int lda, int incx, int incy)
{
    int i;
    int rowsA,colsA,rowsB,colsB;

    printf("[");
    for(i=0;i<20;i++) {
        printf("%3.0f,",y[i]);
    }
    printf("]");

    if(trans==CblasNoTrans) {rowsA=m;colsA=n;} else {rowsA=n;colsA=m;}
    printf(" mxA=%d,mxX=%d,mxY=%d\n",
        (m-1)*lda+(n-1),
        (colsA-1)*incx,
        (rowsA-1)*incy);
}

void test_sgemv_trans(int argc, char *argv[])
{
    int i,j;
    int m=1;
    int n=20;
    int k=1;
    int incx=1;
    int incy=1;
    int lda=1;
    int ldb=1;
    int ldc=1;
    float *a,*b,*c,*x,*y;
    float alpha = 1.0;
    float beta =  0.0;
    int trans;

    //if(argc>1)
    //    n=atoi(argv[1]);
    //if(argc>2)
    //    incx=atoi(argv[2]);
    //printf("n=%d,incx=%d\n",n,incx);

    // y := alpha * Ax + beta * y


    //                 0     1     2     3     4     5     6     7     8     9
    float a3[20] = {  1.0,  2.0,  3.0,
                      4.0,  5.0,  6.0,
                      7.0,  8.0,  9.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float x3[20] = {  1.0, 10.0,100.0, 1000.0, 10000.0, 99.0, 99.0, 99.0, 99.0, 99.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float y3[20] = { 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0,
                     99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0 };

    m=3;
    n=3;
    printf("a(%d,%d) * x(%d) ==> y(%d)\n",m,n,n,m);

    incx = 1;
    incy = 1;

    alpha = 1.0;
    a = a3;
    x = x3;
    beta =  0.0;
    y = y3;

    lda = n;
    trans = CblasNoTrans;
    cblas_sgemv(CblasRowMajor, trans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("N=");
    calc_sgemv_bufMax(y, trans, m, n, lda, incx, incy);

    lda = n;
    trans = CblasTrans;
    for(i=0;i<20;i++) { y3[i] = 99.0; }
    cblas_sgemv(CblasRowMajor, trans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("T=");
    calc_sgemv_bufMax(y, trans, m, n, lda, incx, incy);

    printf("===\n");

    m=3;
    n=2;

    printf("a(%d,%d) * x(%d) ==> y(%d)\n",m,n,n,m);
    lda = n;
    trans = CblasNoTrans;
    for(i=0;i<20;i++) { y3[i] = 99.0; }
    cblas_sgemv(CblasRowMajor, trans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("N=");
    calc_sgemv_bufMax(y, trans, m, n, lda, incx, incy);

    printf("a(%d,%d).T * x(%d) ==> y(%d)\n",m,n,m,n);
    lda = n;
    trans = CblasTrans;
    for(i=0;i<20;i++) { y3[i] = 99.0; }
    cblas_sgemv(CblasRowMajor, trans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("T=");
    calc_sgemv_bufMax(y, trans, m, n, lda, incx, incy);

    printf("===\n");

    m=2;
    n=3;

    printf("a(%d,%d) * x(%d) ==> y(%d)\n",m,n,n,m);
    lda = n;
    trans = CblasNoTrans;
    for(i=0;i<20;i++) { y3[i] = 99.0; }
    cblas_sgemv(CblasRowMajor, trans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("N=");
    calc_sgemv_bufMax(y, trans, m, n, lda, incx, incy);

    printf("a(%d,%d).T * x(%d) ==> y(%d)\n",m,n,m,n);
    lda = n;
    trans = CblasTrans;
    for(i=0;i<20;i++) { y3[i] = 99.0; }
    cblas_sgemv(CblasRowMajor, trans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("T=");
    calc_sgemv_bufMax(y, trans, m, n, lda, incx, incy);

    printf("===\n");

    m=3;
    n=2;

    printf("a(%d,%d) * x(%d).inc2 ==> y(%d)\n",m,n,n,m);
    lda = n;
    incx = 2;
    trans = CblasNoTrans;
    for(i=0;i<20;i++) { y3[i] = 99.0; }
    cblas_sgemv(CblasRowMajor, trans,  m, n,
                alpha, a, lda,  x, incx,  beta,  y, incy);
    printf("N=");
    calc_sgemv_bufMax(y, trans, m, n, lda, incx, incy);
}

void test_sgemm(int argc, char *argv[])
{
    int i,j;
    int m=1;
    int n=20;
    int k=1;
    int incx=1;
    int incy=1;
    int lda=1;
    int ldb=1;
    int ldc=1;
    float *a,*b,*c,*x,*y;
    float alpha = 1.0;
    float beta =  0.0;

    if(argc>1)
        n=atoi(argv[1]);
    if(argc>2)
        incx=atoi(argv[2]);
    printf("n=%d,incx=%d\n",n,incx);

    //                 0     1     2     3     4     5     6     7     8     9
    float a4[20] = {  1.0,  2.0,  3.0,
                      4.0,  5.0,  6.0,
                      7.0,  8.0,  9.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float b4[20] = {  2.0,  3.0,  4.0,
                      5.0,  6.0,  7.0,
                      8.0,  9.0,  1.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float c4[20] = { 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0,
                     99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0 };
    m=3;
    n=3;
    k=3;
    lda = 3;
    ldb = 3;
    ldc = 3;

    alpha = 1.0;
    a = a4;
    b = b4;
    beta =  0.0;
    c = c4;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("[");
    for(i=0;i<20;i++) {
        printf("%f,",c[i]);
    }
    printf("]\n");
}

void calc_sgemm_bufMax(
    float *c,
    int transa,int transb,int m, int n, int k,
    int lda, int ldb, int ldc)
{
    int i;
    int rowsA,colsA,rowsB,colsB;

    printf("[");
    for(i=0;i<20;i++) {
        printf("%2.0f,",c[i]);
    }
    printf("]");

    if(transa==CblasNoTrans) {rowsA=m;colsA=k;} else {rowsA=k;colsA=m;}
    if(transb==CblasNoTrans) {rowsB=k;colsB=n;} else {rowsB=n;colsB=k;}
    printf(" mxA=%d,mxB=%d,mxC=%d\n" ,(rowsA-1)*lda+(colsA-1) , (rowsB-1)*ldb+(colsB-1), (m-1)*ldc+(n-1));
}

void test_sgemm_trans(int argc, char *argv[])
{
    int i,j;
    int m=1;
    int n=20;
    int k=1;
    int incx=1;
    int incy=1;
    int lda=1;
    int ldb=1;
    int ldc=1;
    float *a,*b,*c,*x,*y;
    float alpha = 1.0;
    float beta =  0.0;
    int transa,transb;
    //                 0     1     2     3     4     5     6     7     8     9
    float a4[20] = {  1.0,  2.0,  3.0,
                      4.0,  5.0,  6.0,
                      7.0,  8.0,  9.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float b4[20] = {  1.0,  0.0,  0.0,
                      0.0,  1.0,  0.0,
                      0.0,  0.0,  1.0 };
    //                 0     1     2     3     4     5     6     7     8     9
    float c4[20] = { 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0,
                     99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0, 99.0 };

    m=3;
    n=3;
    k=3;
    lda = 3;
    ldb = 3;
    ldc = 3;
    printf("a(%d,%d) * b(%d,%d) ==> c(%d,%d)\n",m,k,n,k,m,n);

    alpha = 1.0;
    a = a4;
    b = b4;
    beta =  0.0;
    c = c4;
    transa = CblasNoTrans;
    transb = CblasNoTrans;
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Na,Nb=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);

    transa = CblasTrans;
    transb = CblasNoTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Ta,Nb=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);

    transa = CblasNoTrans;
    transb = CblasTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Na,Tb=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);

    a = b4;
    b = a4;
    transa = CblasNoTrans;
    transb = CblasTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Nb,Ta=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);

    a = b4;
    b = a4;
    transa = CblasNoTrans;
    transb = CblasNoTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Nb,Na=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);

    printf("===\n");

    a = a4; // (2,3)
    b = b4; // (3,3)
    m=2;
    n=3;
    k=3;
    printf("a(%d,%d) * b(%d,%d) ==> c(%d,%d)\n",m,k, k,n, m,n);

    lda = k; // (m,k)
    ldb = n; // (k,n)
    ldc = n; // (m,n)
    transa = CblasNoTrans;
    transb = CblasNoTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Na,Nb=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);

    lda = m; // (k,m) // <= trans
    ldb = n; // (k,n)
    ldc = n; // (m,n)
    transa = CblasTrans;
    transb = CblasNoTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Ta,Nb=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);


    printf("===\n");

    a = b4; // (3,3)
    b = a4; // (3,2)
    m=3;
    n=2;
    k=3;
    printf("b(%d,%d) * a(%d,%d) ==> c(%d,%d)\n",m,k, k,n, m,n);

    lda = k; // (m,k)
    ldb = n; // (k,n)
    ldc = n; // (m,n)
    transa = CblasNoTrans;
    transb = CblasNoTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Nb,Na=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);

    lda = k; // (m,k)
    ldb = k; // (n,k) // <= trans
    ldc = n; // (m,n)
    transa = CblasNoTrans;
    transb = CblasTrans;
    for(i=0;i<20;i++) { c4[i] = 99.0; }
    cblas_sgemm(CblasRowMajor, transa, transb,  m, n, k,
                alpha, a, lda,  b, ldb,  beta,  c, ldc);
    printf("Nb,Ta=");
    calc_sgemm_bufMax(c,transa,transb,m,n,k,lda,ldb,ldc);
}

int main(int argc, char **argv)
{

    //printf("char=%d\n",(int)sizeof(char));
    //printf("short int=%d\n",(int)sizeof(short int));
    //printf("int=%d\n",(int)sizeof(int));
    //printf("long=%d\n",(int)sizeof(long));
    //printf("long int=%d\n",(int)sizeof(long int));
    //printf("long long=%d\n",(int)sizeof(long long int));
    //printf("--\n");

    //for(i=0;i<argc;i++) {
    //    printf("argv[%d]=%s\n",i,argv[i]);
    //}

    if(argc<=1) {
        printf("Must give a command\n");
        return -1;
    }
    char *cmd = argv[1];
    argv++;
    argc--;
    if(strcmp(cmd,"info")==0) {
        test_info(argc,argv);
    } else if(strcmp(cmd,"isamax")==0) {
        test_isamax(argc,argv);
    } else if(strcmp(cmd,"sasum")==0) {
        test_sasum(argc,argv);
    } else if(strcmp(cmd,"sgemv")==0) {
        test_sgemv(argc,argv);
    } else if(strcmp(cmd,"sgemv_trans")==0) {
        test_sgemv_trans(argc,argv);
    } else if(strcmp(cmd,"sgemm")==0) {
        test_sgemm(argc,argv);
    } else if(strcmp(cmd,"sgemm_trans")==0) {
        test_sgemm_trans(argc,argv);
    } else {
        printf("unknown command: %s\n",cmd);
        return -1;
    }
    return 0;
}

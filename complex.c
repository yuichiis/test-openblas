#include <stdio.h>
#include <cblas.h>
#include <string.h>

void print_complex(int n, void *x)
{
    openblas_complex_float* c = x;
    for(int i=0;i<n;i++) {
        printf("[%f+%fi],",
            openblas_complex_float_real(c[i]),
            openblas_complex_float_imag(c[i])
        );
    }
}

void test_cscal(int argc, char *argv[])
{
    int n=4;
    int incx=1;
    float alpha[2] = {0.0, 1.0};

    if(argc>1)
        n=atoi(argv[1]);
    if(argc>2)
        incx=atoi(argv[2]);
    printf("n=%d,incx=%d\n",n,incx);

    //                  0            1            2            3
    float x1[4][2] = {  {1.0, 0.0},  {0.0, 1.0},  {1.0, 2.0},  {3.0, 4.0} };
    printf("cscal--\n");
    print_complex(n,x1);
    printf("\n");
    print_complex(1,&alpha);
    printf("\n");
    cblas_cscal(n, &alpha, x1, incx);
    print_complex(n,x1);
    printf("--\n");
    printf("--\n");
}

void test_cdot(int argc, char *argv[])
{
    openblas_complex_float result;
    int n=4;
    int incx=1;
    int incy=1;

    if(argc>1)
        n=atoi(argv[1]);
    if(argc>2)
        incx=atoi(argv[2]);
    printf("n=%d,incx=%d\n",n,incx);

    //                  0            1            2            3
    float x1[4][2] = {  {1.0, 0.0},  {0.0, 1.0},  {1.0, 2.0},  {3.0, 4.0} };
    float y1[4][2] = {  {0.0, 1.0},  {1.0, 0.0},  {2.0, 1.0},  {4.0, 3.0} };
    printf("cdotu--\n");
    print_complex(n,x1);
    printf("\n");
    print_complex(n,y1);
    printf("\n");
    result = cblas_cdotu(n, x1, incx, y1, incy);
    print_complex(1,&result);
    printf("--\n");
    printf("--\n");

    printf("cdotc--\n");
    print_complex(n,x1);
    printf("\n");
    print_complex(n,y1);
    printf("\n");
    result = cblas_cdotc(n, x1, incx, y1, incy);
    print_complex(1,&result);
    printf("--\n");
    printf("--\n");
}

int main(int argc, char **argv)
{
    test_cscal(argc,argv);
    test_cdot(argc,argv);
    return 0;
}
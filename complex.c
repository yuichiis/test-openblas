#include <stdio.h>
#include <cblas.h>
#include <string.h>

void print_complex(int n, float x[][2])
{
    for(int i=0;i<n;i++) {
        printf("[%f+%fi],",x[i][0],x[i][1]);
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
}

int main(int argc, char **argv)
{
    test_cscal(argc,argv);
    return 0;
}
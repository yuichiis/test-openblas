#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__)
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#endif

#include <string.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif

#if defined(__APPLE__)
#else
#include <lapacke.h>
#endif


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
    printf("--\n");
    printf("\n");
}
void test_sasum(int argc, char *argv[])
{
    //int i,j;
    int m=1;
    int n=20;
    int k=1;
    int incx=1;
    int incy=1;
    int lda=1;
    int ldb=1;
    int ldc=1;
    //float *a,*b,*c,*x,*y;
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
    printf("sasum=%f\n",cblas_sasum(n, x2, incx));
    //printf("ssum=%d\n", ssum( n, x2, incx));
    printf("--\n");
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
    } else if(strcmp(cmd,"sasum")==0) {
        test_sasum(argc,argv);
    } else {
        printf("unknown command: %s\n",cmd);
        return -1;
    }
    return 0;
}

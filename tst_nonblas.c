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
    printf("--\n");
    printf("\n");
}
void test_nonblas(int argc, char *argv[])
{
    int n=10;
    int incx=1;

    if(argc>1)
        n=atoi(argv[1]);
    if(argc>2)
        incx=atoi(argv[2]);
    printf("n=%d,incx=%d\n",n,incx);

    //                 0     1     2     3     4     5     6     7     8     9
    float x2[10] = { -3.0,  -2.0, -1.0, 0.0,  1.0,  2.0,  3.0,  4.0,  5.0,  6.0 };
    printf("ssum=%f\n",cblas_ssum(n, x2, incx));
    printf("ismax=%zd\n", cblas_ismax( n, x2, incx));
    printf("ismin=%zd\n", cblas_ismin( n, x2, incx));
    printf("samin=%zd\n", cblas_isamin( n, x2, incx));
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
    } else if(strcmp(cmd,"nonblas")==0) {
        test_nonblas(argc,argv);
    } else {
        printf("unknown command: %s\n",cmd);
        return -1;
    }
    return 0;
}

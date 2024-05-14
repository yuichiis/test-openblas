#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssytrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssytrd_work)( /* LAPACKE_ssytrd_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* d */,
    float *            /* e */,
    float *            /* tau */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_ssytrd_work _g_LAPACKE_ssytrd_work = NULL;
lapack_int LAPACKE_ssytrd_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            d,
    float *            e,
    float *            tau,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_ssytrd_work==NULL) {
        _g_LAPACKE_ssytrd_work = rindow_load_libopenblas_func("LAPACKE_ssytrd_work"); 
        if(_g_LAPACKE_ssytrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssytrd_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        d,
        e,
        tau,
        work,
        lwork    
    );
}

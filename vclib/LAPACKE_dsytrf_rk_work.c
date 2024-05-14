#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsytrf_rk_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsytrf_rk_work)( /* LAPACKE_dsytrf_rk_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* e */,
    lapack_int *            /* ipiv */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dsytrf_rk_work _g_LAPACKE_dsytrf_rk_work = NULL;
lapack_int LAPACKE_dsytrf_rk_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            e,
    lapack_int *            ipiv,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dsytrf_rk_work==NULL) {
        _g_LAPACKE_dsytrf_rk_work = rindow_load_libopenblas_func("LAPACKE_dsytrf_rk_work"); 
        if(_g_LAPACKE_dsytrf_rk_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsytrf_rk_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        e,
        ipiv,
        work,
        lwork    
    );
}

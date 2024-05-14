#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpstrf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpstrf_work)( /* LAPACKE_dpstrf_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* piv */,
    lapack_int *            /* rank */,
    double            /* tol */,
    double *            /* work */
);
static PFNLAPACKE_dpstrf_work _g_LAPACKE_dpstrf_work = NULL;
lapack_int LAPACKE_dpstrf_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            piv,
    lapack_int *            rank,
    double            tol,
    double *            work
)
{
    if(_g_LAPACKE_dpstrf_work==NULL) {
        _g_LAPACKE_dpstrf_work = rindow_load_libopenblas_func("LAPACKE_dpstrf_work"); 
        if(_g_LAPACKE_dpstrf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpstrf_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        piv,
        rank,
        tol,
        work    
    );
}

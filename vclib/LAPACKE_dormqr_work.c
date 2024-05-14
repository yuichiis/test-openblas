#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dormqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dormqr_work)( /* LAPACKE_dormqr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dormqr_work _g_LAPACKE_dormqr_work = NULL;
lapack_int LAPACKE_dormqr_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const double *            a,
    lapack_int            lda,
    const double *            tau,
    double *            c,
    lapack_int            ldc,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dormqr_work==NULL) {
        _g_LAPACKE_dormqr_work = rindow_load_libopenblas_func("LAPACKE_dormqr_work"); 
        if(_g_LAPACKE_dormqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dormqr_work(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        tau,
        c,
        ldc,
        work,
        lwork    
    );
}

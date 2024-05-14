#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dormtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dormtr_work)( /* LAPACKE_dormtr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dormtr_work _g_LAPACKE_dormtr_work = NULL;
lapack_int LAPACKE_dormtr_work(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    const double *            tau,
    double *            c,
    lapack_int            ldc,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dormtr_work==NULL) {
        _g_LAPACKE_dormtr_work = rindow_load_libopenblas_func("LAPACKE_dormtr_work"); 
        if(_g_LAPACKE_dormtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dormtr_work(
        matrix_layout,
        side,
        uplo,
        trans,
        m,
        n,
        a,
        lda,
        tau,
        c,
        ldc,
        work,
        lwork    
    );
}

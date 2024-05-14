#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgemlq_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgemlq_work)( /* LAPACKE_dgemlq_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* t */,
    lapack_int            /* tsize */,
    double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dgemlq_work _g_LAPACKE_dgemlq_work = NULL;
lapack_int LAPACKE_dgemlq_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const double *            a,
    lapack_int            lda,
    const double *            t,
    lapack_int            tsize,
    double *            c,
    lapack_int            ldc,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dgemlq_work==NULL) {
        _g_LAPACKE_dgemlq_work = rindow_load_libopenblas_func("LAPACKE_dgemlq_work"); 
        if(_g_LAPACKE_dgemlq_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgemlq_work(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        t,
        tsize,
        c,
        ldc,
        work,
        lwork    
    );
}

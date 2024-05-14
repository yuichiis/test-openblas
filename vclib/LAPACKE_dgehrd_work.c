#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgehrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgehrd_work)( /* LAPACKE_dgehrd_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* tau */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dgehrd_work _g_LAPACKE_dgehrd_work = NULL;
lapack_int LAPACKE_dgehrd_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    double *            a,
    lapack_int            lda,
    double *            tau,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dgehrd_work==NULL) {
        _g_LAPACKE_dgehrd_work = rindow_load_libopenblas_func("LAPACKE_dgehrd_work"); 
        if(_g_LAPACKE_dgehrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgehrd_work(
        matrix_layout,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau,
        work,
        lwork    
    );
}

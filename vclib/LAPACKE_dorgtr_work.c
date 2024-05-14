#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dorgtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dorgtr_work)( /* LAPACKE_dorgtr_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dorgtr_work _g_LAPACKE_dorgtr_work = NULL;
lapack_int LAPACKE_dorgtr_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    const double *            tau,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dorgtr_work==NULL) {
        _g_LAPACKE_dorgtr_work = rindow_load_libopenblas_func("LAPACKE_dorgtr_work"); 
        if(_g_LAPACKE_dorgtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dorgtr_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        tau,
        work,
        lwork    
    );
}

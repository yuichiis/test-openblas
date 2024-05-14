#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgecon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgecon_work)( /* LAPACKE_zgecon_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double            /* anorm */,
    double *            /* rcond */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zgecon_work _g_LAPACKE_zgecon_work = NULL;
lapack_int LAPACKE_zgecon_work(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    double            anorm,
    double *            rcond,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zgecon_work==NULL) {
        _g_LAPACKE_zgecon_work = rindow_load_libopenblas_func("LAPACKE_zgecon_work"); 
        if(_g_LAPACKE_zgecon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgecon_work(
        matrix_layout,
        norm,
        n,
        a,
        lda,
        anorm,
        rcond,
        work,
        rwork    
    );
}

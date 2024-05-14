#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stpcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stpcon_work)( /* LAPACKE_stpcon_work */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const float *            /* ap */,
    float *            /* rcond */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_stpcon_work _g_LAPACKE_stpcon_work = NULL;
lapack_int LAPACKE_stpcon_work(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const float *            ap,
    float *            rcond,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_stpcon_work==NULL) {
        _g_LAPACKE_stpcon_work = rindow_load_libopenblas_func("LAPACKE_stpcon_work"); 
        if(_g_LAPACKE_stpcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stpcon_work(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        ap,
        rcond,
        work,
        iwork    
    );
}

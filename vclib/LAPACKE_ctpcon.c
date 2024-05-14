#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctpcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctpcon)( /* LAPACKE_ctpcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    float *            /* rcond */
);
static PFNLAPACKE_ctpcon _g_LAPACKE_ctpcon = NULL;
lapack_int LAPACKE_ctpcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const lapack_complex_float *            ap,
    float *            rcond
)
{
    if(_g_LAPACKE_ctpcon==NULL) {
        _g_LAPACKE_ctpcon = rindow_load_libopenblas_func("LAPACKE_ctpcon"); 
        if(_g_LAPACKE_ctpcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctpcon(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        ap,
        rcond    
    );
}

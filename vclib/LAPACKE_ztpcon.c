#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztpcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztpcon)( /* LAPACKE_ztpcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    double *            /* rcond */
);
static PFNLAPACKE_ztpcon _g_LAPACKE_ztpcon = NULL;
lapack_int LAPACKE_ztpcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const lapack_complex_double *            ap,
    double *            rcond
)
{
    if(_g_LAPACKE_ztpcon==NULL) {
        _g_LAPACKE_ztpcon = rindow_load_libopenblas_func("LAPACKE_ztpcon"); 
        if(_g_LAPACKE_ztpcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztpcon(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        ap,
        rcond    
    );
}

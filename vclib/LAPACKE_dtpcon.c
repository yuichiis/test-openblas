#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtpcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtpcon)( /* LAPACKE_dtpcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const double *            /* ap */,
    double *            /* rcond */
);
static PFNLAPACKE_dtpcon _g_LAPACKE_dtpcon = NULL;
lapack_int LAPACKE_dtpcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const double *            ap,
    double *            rcond
)
{
    if(_g_LAPACKE_dtpcon==NULL) {
        _g_LAPACKE_dtpcon = rindow_load_libopenblas_func("LAPACKE_dtpcon"); 
        if(_g_LAPACKE_dtpcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtpcon(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        ap,
        rcond    
    );
}

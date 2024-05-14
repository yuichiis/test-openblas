#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stpcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stpcon)( /* LAPACKE_stpcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const float *            /* ap */,
    float *            /* rcond */
);
static PFNLAPACKE_stpcon _g_LAPACKE_stpcon = NULL;
lapack_int LAPACKE_stpcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const float *            ap,
    float *            rcond
)
{
    if(_g_LAPACKE_stpcon==NULL) {
        _g_LAPACKE_stpcon = rindow_load_libopenblas_func("LAPACKE_stpcon"); 
        if(_g_LAPACKE_stpcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stpcon(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        ap,
        rcond    
    );
}

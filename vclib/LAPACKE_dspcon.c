#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dspcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dspcon)( /* LAPACKE_dspcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* ap */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dspcon _g_LAPACKE_dspcon = NULL;
lapack_int LAPACKE_dspcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            ap,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dspcon==NULL) {
        _g_LAPACKE_dspcon = rindow_load_libopenblas_func("LAPACKE_dspcon"); 
        if(_g_LAPACKE_dspcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dspcon(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv,
        anorm,
        rcond    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sspcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sspcon)( /* LAPACKE_sspcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* ap */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_sspcon _g_LAPACKE_sspcon = NULL;
lapack_int LAPACKE_sspcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            ap,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_sspcon==NULL) {
        _g_LAPACKE_sspcon = rindow_load_libopenblas_func("LAPACKE_sspcon"); 
        if(_g_LAPACKE_sspcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sspcon(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv,
        anorm,
        rcond    
    );
}

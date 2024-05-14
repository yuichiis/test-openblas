#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chpcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chpcon)( /* LAPACKE_chpcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_chpcon _g_LAPACKE_chpcon = NULL;
lapack_int LAPACKE_chpcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            ap,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_chpcon==NULL) {
        _g_LAPACKE_chpcon = rindow_load_libopenblas_func("LAPACKE_chpcon"); 
        if(_g_LAPACKE_chpcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chpcon(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv,
        anorm,
        rcond    
    );
}

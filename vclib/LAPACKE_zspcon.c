#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zspcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zspcon)( /* LAPACKE_zspcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zspcon _g_LAPACKE_zspcon = NULL;
lapack_int LAPACKE_zspcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            ap,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zspcon==NULL) {
        _g_LAPACKE_zspcon = rindow_load_libopenblas_func("LAPACKE_zspcon"); 
        if(_g_LAPACKE_zspcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zspcon(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv,
        anorm,
        rcond    
    );
}

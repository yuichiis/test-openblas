#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zppcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zppcon)( /* LAPACKE_zppcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zppcon _g_LAPACKE_zppcon = NULL;
lapack_int LAPACKE_zppcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            ap,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zppcon==NULL) {
        _g_LAPACKE_zppcon = rindow_load_libopenblas_func("LAPACKE_zppcon"); 
        if(_g_LAPACKE_zppcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zppcon(
        matrix_layout,
        uplo,
        n,
        ap,
        anorm,
        rcond    
    );
}

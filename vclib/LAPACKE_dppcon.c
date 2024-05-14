#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dppcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dppcon)( /* LAPACKE_dppcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* ap */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dppcon _g_LAPACKE_dppcon = NULL;
lapack_int LAPACKE_dppcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            ap,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dppcon==NULL) {
        _g_LAPACKE_dppcon = rindow_load_libopenblas_func("LAPACKE_dppcon"); 
        if(_g_LAPACKE_dppcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dppcon(
        matrix_layout,
        uplo,
        n,
        ap,
        anorm,
        rcond    
    );
}

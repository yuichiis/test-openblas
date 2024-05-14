#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cppcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cppcon)( /* LAPACKE_cppcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_cppcon _g_LAPACKE_cppcon = NULL;
lapack_int LAPACKE_cppcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            ap,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_cppcon==NULL) {
        _g_LAPACKE_cppcon = rindow_load_libopenblas_func("LAPACKE_cppcon"); 
        if(_g_LAPACKE_cppcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cppcon(
        matrix_layout,
        uplo,
        n,
        ap,
        anorm,
        rcond    
    );
}

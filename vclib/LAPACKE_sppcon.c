#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sppcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sppcon)( /* LAPACKE_sppcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* ap */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_sppcon _g_LAPACKE_sppcon = NULL;
lapack_int LAPACKE_sppcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            ap,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_sppcon==NULL) {
        _g_LAPACKE_sppcon = rindow_load_libopenblas_func("LAPACKE_sppcon"); 
        if(_g_LAPACKE_sppcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sppcon(
        matrix_layout,
        uplo,
        n,
        ap,
        anorm,
        rcond    
    );
}

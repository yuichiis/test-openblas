#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cptcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cptcon)( /* LAPACKE_cptcon */
    lapack_int            /* n */,
    const float *            /* d */,
    const lapack_complex_float *            /* e */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_cptcon _g_LAPACKE_cptcon = NULL;
lapack_int LAPACKE_cptcon(
    lapack_int            n,
    const float *            d,
    const lapack_complex_float *            e,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_cptcon==NULL) {
        _g_LAPACKE_cptcon = rindow_load_libopenblas_func("LAPACKE_cptcon"); 
        if(_g_LAPACKE_cptcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cptcon(
        n,
        d,
        e,
        anorm,
        rcond    
    );
}

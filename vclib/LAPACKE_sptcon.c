#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sptcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sptcon)( /* LAPACKE_sptcon */
    lapack_int            /* n */,
    const float *            /* d */,
    const float *            /* e */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_sptcon _g_LAPACKE_sptcon = NULL;
lapack_int LAPACKE_sptcon(
    lapack_int            n,
    const float *            d,
    const float *            e,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_sptcon==NULL) {
        _g_LAPACKE_sptcon = rindow_load_libopenblas_func("LAPACKE_sptcon"); 
        if(_g_LAPACKE_sptcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sptcon(
        n,
        d,
        e,
        anorm,
        rcond    
    );
}

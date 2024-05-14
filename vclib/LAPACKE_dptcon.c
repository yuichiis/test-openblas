#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dptcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dptcon)( /* LAPACKE_dptcon */
    lapack_int            /* n */,
    const double *            /* d */,
    const double *            /* e */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dptcon _g_LAPACKE_dptcon = NULL;
lapack_int LAPACKE_dptcon(
    lapack_int            n,
    const double *            d,
    const double *            e,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dptcon==NULL) {
        _g_LAPACKE_dptcon = rindow_load_libopenblas_func("LAPACKE_dptcon"); 
        if(_g_LAPACKE_dptcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dptcon(
        n,
        d,
        e,
        anorm,
        rcond    
    );
}

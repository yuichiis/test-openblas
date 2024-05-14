#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zptcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zptcon)( /* LAPACKE_zptcon */
    lapack_int            /* n */,
    const double *            /* d */,
    const lapack_complex_double *            /* e */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zptcon _g_LAPACKE_zptcon = NULL;
lapack_int LAPACKE_zptcon(
    lapack_int            n,
    const double *            d,
    const lapack_complex_double *            e,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zptcon==NULL) {
        _g_LAPACKE_zptcon = rindow_load_libopenblas_func("LAPACKE_zptcon"); 
        if(_g_LAPACKE_zptcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zptcon(
        n,
        d,
        e,
        anorm,
        rcond    
    );
}

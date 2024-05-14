#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgtcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgtcon)( /* LAPACKE_dgtcon */
    char            /* norm */,
    lapack_int            /* n */,
    const double *            /* dl */,
    const double *            /* d */,
    const double *            /* du */,
    const double *            /* du2 */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dgtcon _g_LAPACKE_dgtcon = NULL;
lapack_int LAPACKE_dgtcon(
    char            norm,
    lapack_int            n,
    const double *            dl,
    const double *            d,
    const double *            du,
    const double *            du2,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dgtcon==NULL) {
        _g_LAPACKE_dgtcon = rindow_load_libopenblas_func("LAPACKE_dgtcon"); 
        if(_g_LAPACKE_dgtcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgtcon(
        norm,
        n,
        dl,
        d,
        du,
        du2,
        ipiv,
        anorm,
        rcond    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgtcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgtcon)( /* LAPACKE_zgtcon */
    char            /* norm */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* dl */,
    const lapack_complex_double *            /* d */,
    const lapack_complex_double *            /* du */,
    const lapack_complex_double *            /* du2 */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zgtcon _g_LAPACKE_zgtcon = NULL;
lapack_int LAPACKE_zgtcon(
    char            norm,
    lapack_int            n,
    const lapack_complex_double *            dl,
    const lapack_complex_double *            d,
    const lapack_complex_double *            du,
    const lapack_complex_double *            du2,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zgtcon==NULL) {
        _g_LAPACKE_zgtcon = rindow_load_libopenblas_func("LAPACKE_zgtcon"); 
        if(_g_LAPACKE_zgtcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgtcon(
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

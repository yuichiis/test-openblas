#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgtcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgtcon)( /* LAPACKE_cgtcon */
    char            /* norm */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* dl */,
    const lapack_complex_float *            /* d */,
    const lapack_complex_float *            /* du */,
    const lapack_complex_float *            /* du2 */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_cgtcon _g_LAPACKE_cgtcon = NULL;
lapack_int LAPACKE_cgtcon(
    char            norm,
    lapack_int            n,
    const lapack_complex_float *            dl,
    const lapack_complex_float *            d,
    const lapack_complex_float *            du,
    const lapack_complex_float *            du2,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_cgtcon==NULL) {
        _g_LAPACKE_cgtcon = rindow_load_libopenblas_func("LAPACKE_cgtcon"); 
        if(_g_LAPACKE_cgtcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgtcon(
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

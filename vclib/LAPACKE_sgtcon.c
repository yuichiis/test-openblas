#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgtcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgtcon)( /* LAPACKE_sgtcon */
    char            /* norm */,
    lapack_int            /* n */,
    const float *            /* dl */,
    const float *            /* d */,
    const float *            /* du */,
    const float *            /* du2 */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_sgtcon _g_LAPACKE_sgtcon = NULL;
lapack_int LAPACKE_sgtcon(
    char            norm,
    lapack_int            n,
    const float *            dl,
    const float *            d,
    const float *            du,
    const float *            du2,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_sgtcon==NULL) {
        _g_LAPACKE_sgtcon = rindow_load_libopenblas_func("LAPACKE_sgtcon"); 
        if(_g_LAPACKE_sgtcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgtcon(
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

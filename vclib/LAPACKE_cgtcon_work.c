#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgtcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgtcon_work)( /* LAPACKE_cgtcon_work */
    char            /* norm */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* dl */,
    const lapack_complex_float *            /* d */,
    const lapack_complex_float *            /* du */,
    const lapack_complex_float *            /* du2 */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */,
    lapack_complex_float *            /* work */
);
static PFNLAPACKE_cgtcon_work _g_LAPACKE_cgtcon_work = NULL;
lapack_int LAPACKE_cgtcon_work(
    char            norm,
    lapack_int            n,
    const lapack_complex_float *            dl,
    const lapack_complex_float *            d,
    const lapack_complex_float *            du,
    const lapack_complex_float *            du2,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond,
    lapack_complex_float *            work
)
{
    if(_g_LAPACKE_cgtcon_work==NULL) {
        _g_LAPACKE_cgtcon_work = rindow_load_libopenblas_func("LAPACKE_cgtcon_work"); 
        if(_g_LAPACKE_cgtcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgtcon_work(
        norm,
        n,
        dl,
        d,
        du,
        du2,
        ipiv,
        anorm,
        rcond,
        work    
    );
}

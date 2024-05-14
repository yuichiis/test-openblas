#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgtcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgtcon_work)( /* LAPACKE_zgtcon_work */
    char            /* norm */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* dl */,
    const lapack_complex_double *            /* d */,
    const lapack_complex_double *            /* du */,
    const lapack_complex_double *            /* du2 */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zgtcon_work _g_LAPACKE_zgtcon_work = NULL;
lapack_int LAPACKE_zgtcon_work(
    char            norm,
    lapack_int            n,
    const lapack_complex_double *            dl,
    const lapack_complex_double *            d,
    const lapack_complex_double *            du,
    const lapack_complex_double *            du2,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zgtcon_work==NULL) {
        _g_LAPACKE_zgtcon_work = rindow_load_libopenblas_func("LAPACKE_zgtcon_work"); 
        if(_g_LAPACKE_zgtcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgtcon_work(
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

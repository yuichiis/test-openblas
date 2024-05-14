#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgtcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgtcon_work)( /* LAPACKE_sgtcon_work */
    char            /* norm */,
    lapack_int            /* n */,
    const float *            /* dl */,
    const float *            /* d */,
    const float *            /* du */,
    const float *            /* du2 */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sgtcon_work _g_LAPACKE_sgtcon_work = NULL;
lapack_int LAPACKE_sgtcon_work(
    char            norm,
    lapack_int            n,
    const float *            dl,
    const float *            d,
    const float *            du,
    const float *            du2,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_sgtcon_work==NULL) {
        _g_LAPACKE_sgtcon_work = rindow_load_libopenblas_func("LAPACKE_sgtcon_work"); 
        if(_g_LAPACKE_sgtcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgtcon_work(
        norm,
        n,
        dl,
        d,
        du,
        du2,
        ipiv,
        anorm,
        rcond,
        work,
        iwork    
    );
}

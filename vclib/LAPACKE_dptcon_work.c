#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dptcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dptcon_work)( /* LAPACKE_dptcon_work */
    lapack_int            /* n */,
    const double *            /* d */,
    const double *            /* e */,
    double            /* anorm */,
    double *            /* rcond */,
    double *            /* work */
);
static PFNLAPACKE_dptcon_work _g_LAPACKE_dptcon_work = NULL;
lapack_int LAPACKE_dptcon_work(
    lapack_int            n,
    const double *            d,
    const double *            e,
    double            anorm,
    double *            rcond,
    double *            work
)
{
    if(_g_LAPACKE_dptcon_work==NULL) {
        _g_LAPACKE_dptcon_work = rindow_load_libopenblas_func("LAPACKE_dptcon_work"); 
        if(_g_LAPACKE_dptcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dptcon_work(
        n,
        d,
        e,
        anorm,
        rcond,
        work    
    );
}

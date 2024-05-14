#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zptcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zptcon_work)( /* LAPACKE_zptcon_work */
    lapack_int            /* n */,
    const double *            /* d */,
    const lapack_complex_double *            /* e */,
    double            /* anorm */,
    double *            /* rcond */,
    double *            /* work */
);
static PFNLAPACKE_zptcon_work _g_LAPACKE_zptcon_work = NULL;
lapack_int LAPACKE_zptcon_work(
    lapack_int            n,
    const double *            d,
    const lapack_complex_double *            e,
    double            anorm,
    double *            rcond,
    double *            work
)
{
    if(_g_LAPACKE_zptcon_work==NULL) {
        _g_LAPACKE_zptcon_work = rindow_load_libopenblas_func("LAPACKE_zptcon_work"); 
        if(_g_LAPACKE_zptcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zptcon_work(
        n,
        d,
        e,
        anorm,
        rcond,
        work    
    );
}

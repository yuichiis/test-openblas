#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sptcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sptcon_work)( /* LAPACKE_sptcon_work */
    lapack_int            /* n */,
    const float *            /* d */,
    const float *            /* e */,
    float            /* anorm */,
    float *            /* rcond */,
    float *            /* work */
);
static PFNLAPACKE_sptcon_work _g_LAPACKE_sptcon_work = NULL;
lapack_int LAPACKE_sptcon_work(
    lapack_int            n,
    const float *            d,
    const float *            e,
    float            anorm,
    float *            rcond,
    float *            work
)
{
    if(_g_LAPACKE_sptcon_work==NULL) {
        _g_LAPACKE_sptcon_work = rindow_load_libopenblas_func("LAPACKE_sptcon_work"); 
        if(_g_LAPACKE_sptcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sptcon_work(
        n,
        d,
        e,
        anorm,
        rcond,
        work    
    );
}

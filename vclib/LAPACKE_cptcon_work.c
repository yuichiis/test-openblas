#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cptcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cptcon_work)( /* LAPACKE_cptcon_work */
    lapack_int            /* n */,
    const float *            /* d */,
    const lapack_complex_float *            /* e */,
    float            /* anorm */,
    float *            /* rcond */,
    float *            /* work */
);
static PFNLAPACKE_cptcon_work _g_LAPACKE_cptcon_work = NULL;
lapack_int LAPACKE_cptcon_work(
    lapack_int            n,
    const float *            d,
    const lapack_complex_float *            e,
    float            anorm,
    float *            rcond,
    float *            work
)
{
    if(_g_LAPACKE_cptcon_work==NULL) {
        _g_LAPACKE_cptcon_work = rindow_load_libopenblas_func("LAPACKE_cptcon_work"); 
        if(_g_LAPACKE_cptcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cptcon_work(
        n,
        d,
        e,
        anorm,
        rcond,
        work    
    );
}

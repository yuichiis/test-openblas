#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpteqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpteqr_work)( /* LAPACKE_cpteqr_work */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* work */
);
static PFNLAPACKE_cpteqr_work _g_LAPACKE_cpteqr_work = NULL;
lapack_int LAPACKE_cpteqr_work(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    float *            d,
    float *            e,
    lapack_complex_float *            z,
    lapack_int            ldz,
    float *            work
)
{
    if(_g_LAPACKE_cpteqr_work==NULL) {
        _g_LAPACKE_cpteqr_work = rindow_load_libopenblas_func("LAPACKE_cpteqr_work"); 
        if(_g_LAPACKE_cpteqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpteqr_work(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz,
        work    
    );
}

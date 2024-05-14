#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssteqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssteqr_work)( /* LAPACKE_ssteqr_work */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* work */
);
static PFNLAPACKE_ssteqr_work _g_LAPACKE_ssteqr_work = NULL;
lapack_int LAPACKE_ssteqr_work(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    float *            d,
    float *            e,
    float *            z,
    lapack_int            ldz,
    float *            work
)
{
    if(_g_LAPACKE_ssteqr_work==NULL) {
        _g_LAPACKE_ssteqr_work = rindow_load_libopenblas_func("LAPACKE_ssteqr_work"); 
        if(_g_LAPACKE_ssteqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssteqr_work(
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

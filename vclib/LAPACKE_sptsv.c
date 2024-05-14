#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sptsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sptsv)( /* LAPACKE_sptsv */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* d */,
    float *            /* e */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sptsv _g_LAPACKE_sptsv = NULL;
lapack_int LAPACKE_sptsv(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    float *            d,
    float *            e,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sptsv==NULL) {
        _g_LAPACKE_sptsv = rindow_load_libopenblas_func("LAPACKE_sptsv"); 
        if(_g_LAPACKE_sptsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sptsv(
        matrix_layout,
        n,
        nrhs,
        d,
        e,
        b,
        ldb    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgtsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgtsv)( /* LAPACKE_sgtsv */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* dl */,
    float *            /* d */,
    float *            /* du */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sgtsv _g_LAPACKE_sgtsv = NULL;
lapack_int LAPACKE_sgtsv(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    float *            dl,
    float *            d,
    float *            du,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sgtsv==NULL) {
        _g_LAPACKE_sgtsv = rindow_load_libopenblas_func("LAPACKE_sgtsv"); 
        if(_g_LAPACKE_sgtsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgtsv(
        matrix_layout,
        n,
        nrhs,
        dl,
        d,
        du,
        b,
        ldb    
    );
}

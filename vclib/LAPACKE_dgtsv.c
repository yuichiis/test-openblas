#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgtsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgtsv)( /* LAPACKE_dgtsv */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* dl */,
    double *            /* d */,
    double *            /* du */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dgtsv _g_LAPACKE_dgtsv = NULL;
lapack_int LAPACKE_dgtsv(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    double *            dl,
    double *            d,
    double *            du,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dgtsv==NULL) {
        _g_LAPACKE_dgtsv = rindow_load_libopenblas_func("LAPACKE_dgtsv"); 
        if(_g_LAPACKE_dgtsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgtsv(
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

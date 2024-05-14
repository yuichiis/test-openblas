#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgtsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgtsv)( /* LAPACKE_cgtsv */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* dl */,
    lapack_complex_float *            /* d */,
    lapack_complex_float *            /* du */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cgtsv _g_LAPACKE_cgtsv = NULL;
lapack_int LAPACKE_cgtsv(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            dl,
    lapack_complex_float *            d,
    lapack_complex_float *            du,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cgtsv==NULL) {
        _g_LAPACKE_cgtsv = rindow_load_libopenblas_func("LAPACKE_cgtsv"); 
        if(_g_LAPACKE_cgtsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgtsv(
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

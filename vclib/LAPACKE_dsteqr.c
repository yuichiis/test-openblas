#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsteqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsteqr)( /* LAPACKE_dsteqr */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dsteqr _g_LAPACKE_dsteqr = NULL;
lapack_int LAPACKE_dsteqr(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    double *            d,
    double *            e,
    double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_dsteqr==NULL) {
        _g_LAPACKE_dsteqr = rindow_load_libopenblas_func("LAPACKE_dsteqr"); 
        if(_g_LAPACKE_dsteqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsteqr(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpteqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpteqr)( /* LAPACKE_dpteqr */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dpteqr _g_LAPACKE_dpteqr = NULL;
lapack_int LAPACKE_dpteqr(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    double *            d,
    double *            e,
    double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_dpteqr==NULL) {
        _g_LAPACKE_dpteqr = rindow_load_libopenblas_func("LAPACKE_dpteqr"); 
        if(_g_LAPACKE_dpteqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpteqr(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz    
    );
}

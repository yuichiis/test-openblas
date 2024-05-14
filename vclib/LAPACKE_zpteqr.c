#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpteqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpteqr)( /* LAPACKE_zpteqr */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_zpteqr _g_LAPACKE_zpteqr = NULL;
lapack_int LAPACKE_zpteqr(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    double *            d,
    double *            e,
    lapack_complex_double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_zpteqr==NULL) {
        _g_LAPACKE_zpteqr = rindow_load_libopenblas_func("LAPACKE_zpteqr"); 
        if(_g_LAPACKE_zpteqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpteqr(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz    
    );
}

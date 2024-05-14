#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpteqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpteqr)( /* LAPACKE_cpteqr */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_cpteqr _g_LAPACKE_cpteqr = NULL;
lapack_int LAPACKE_cpteqr(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    float *            d,
    float *            e,
    lapack_complex_float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_cpteqr==NULL) {
        _g_LAPACKE_cpteqr = rindow_load_libopenblas_func("LAPACKE_cpteqr"); 
        if(_g_LAPACKE_cpteqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpteqr(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz    
    );
}

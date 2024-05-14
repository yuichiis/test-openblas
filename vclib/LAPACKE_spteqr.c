#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spteqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spteqr)( /* LAPACKE_spteqr */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_spteqr _g_LAPACKE_spteqr = NULL;
lapack_int LAPACKE_spteqr(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    float *            d,
    float *            e,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_spteqr==NULL) {
        _g_LAPACKE_spteqr = rindow_load_libopenblas_func("LAPACKE_spteqr"); 
        if(_g_LAPACKE_spteqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spteqr(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz    
    );
}

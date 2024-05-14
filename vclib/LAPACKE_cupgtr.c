#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cupgtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cupgtr)( /* LAPACKE_cupgtr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    const lapack_complex_float *            /* tau */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */
);
static PFNLAPACKE_cupgtr _g_LAPACKE_cupgtr = NULL;
lapack_int LAPACKE_cupgtr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            ap,
    const lapack_complex_float *            tau,
    lapack_complex_float *            q,
    lapack_int            ldq
)
{
    if(_g_LAPACKE_cupgtr==NULL) {
        _g_LAPACKE_cupgtr = rindow_load_libopenblas_func("LAPACKE_cupgtr"); 
        if(_g_LAPACKE_cupgtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cupgtr(
        matrix_layout,
        uplo,
        n,
        ap,
        tau,
        q,
        ldq    
    );
}

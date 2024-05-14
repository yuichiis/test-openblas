#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cupmtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cupmtr)( /* LAPACKE_cupmtr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    const lapack_complex_float *            /* tau */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_cupmtr _g_LAPACKE_cupmtr = NULL;
lapack_int LAPACKE_cupmtr(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            ap,
    const lapack_complex_float *            tau,
    lapack_complex_float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_cupmtr==NULL) {
        _g_LAPACKE_cupmtr = rindow_load_libopenblas_func("LAPACKE_cupmtr"); 
        if(_g_LAPACKE_cupmtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cupmtr(
        matrix_layout,
        side,
        uplo,
        trans,
        m,
        n,
        ap,
        tau,
        c,
        ldc    
    );
}

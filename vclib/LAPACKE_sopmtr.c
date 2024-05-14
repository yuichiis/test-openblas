#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sopmtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sopmtr)( /* LAPACKE_sopmtr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* ap */,
    const float *            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_sopmtr _g_LAPACKE_sopmtr = NULL;
lapack_int LAPACKE_sopmtr(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const float *            ap,
    const float *            tau,
    float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_sopmtr==NULL) {
        _g_LAPACKE_sopmtr = rindow_load_libopenblas_func("LAPACKE_sopmtr"); 
        if(_g_LAPACKE_sopmtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sopmtr(
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

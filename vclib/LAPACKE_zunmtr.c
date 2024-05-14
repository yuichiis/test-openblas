#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zunmtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zunmtr)( /* LAPACKE_zunmtr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_zunmtr _g_LAPACKE_zunmtr = NULL;
lapack_int LAPACKE_zunmtr(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau,
    lapack_complex_double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_zunmtr==NULL) {
        _g_LAPACKE_zunmtr = rindow_load_libopenblas_func("LAPACKE_zunmtr"); 
        if(_g_LAPACKE_zunmtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zunmtr(
        matrix_layout,
        side,
        uplo,
        trans,
        m,
        n,
        a,
        lda,
        tau,
        c,
        ldc    
    );
}

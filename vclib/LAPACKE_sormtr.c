#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sormtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sormtr)( /* LAPACKE_sormtr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_sormtr _g_LAPACKE_sormtr = NULL;
lapack_int LAPACKE_sormtr(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const float *            tau,
    float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_sormtr==NULL) {
        _g_LAPACKE_sormtr = rindow_load_libopenblas_func("LAPACKE_sormtr"); 
        if(_g_LAPACKE_sormtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sormtr(
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

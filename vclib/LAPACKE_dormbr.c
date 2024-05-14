#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dormbr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dormbr)( /* LAPACKE_dormbr */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_dormbr _g_LAPACKE_dormbr = NULL;
lapack_int LAPACKE_dormbr(
    int            matrix_layout,
    char            vect,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const double *            a,
    lapack_int            lda,
    const double *            tau,
    double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_dormbr==NULL) {
        _g_LAPACKE_dormbr = rindow_load_libopenblas_func("LAPACKE_dormbr"); 
        if(_g_LAPACKE_dormbr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dormbr(
        matrix_layout,
        vect,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        tau,
        c,
        ldc    
    );
}

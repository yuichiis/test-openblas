#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zunmbr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zunmbr)( /* LAPACKE_zunmbr */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_zunmbr _g_LAPACKE_zunmbr = NULL;
lapack_int LAPACKE_zunmbr(
    int            matrix_layout,
    char            vect,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau,
    lapack_complex_double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_zunmbr==NULL) {
        _g_LAPACKE_zunmbr = rindow_load_libopenblas_func("LAPACKE_zunmbr"); 
        if(_g_LAPACKE_zunmbr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zunmbr(
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

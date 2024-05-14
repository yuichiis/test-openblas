#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dormrz not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dormrz)( /* LAPACKE_dormrz */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_dormrz _g_LAPACKE_dormrz = NULL;
lapack_int LAPACKE_dormrz(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    const double *            a,
    lapack_int            lda,
    const double *            tau,
    double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_dormrz==NULL) {
        _g_LAPACKE_dormrz = rindow_load_libopenblas_func("LAPACKE_dormrz"); 
        if(_g_LAPACKE_dormrz==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dormrz(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        l,
        a,
        lda,
        tau,
        c,
        ldc    
    );
}

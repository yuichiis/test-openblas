#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dormql not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dormql)( /* LAPACKE_dormql */
    int            /* matrix_layout */,
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
static PFNLAPACKE_dormql _g_LAPACKE_dormql = NULL;
lapack_int LAPACKE_dormql(
    int            matrix_layout,
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
    if(_g_LAPACKE_dormql==NULL) {
        _g_LAPACKE_dormql = rindow_load_libopenblas_func("LAPACKE_dormql"); 
        if(_g_LAPACKE_dormql==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dormql(
        matrix_layout,
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

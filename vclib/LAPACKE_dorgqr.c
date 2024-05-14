#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dorgqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dorgqr)( /* LAPACKE_dorgqr */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */
);
static PFNLAPACKE_dorgqr _g_LAPACKE_dorgqr = NULL;
lapack_int LAPACKE_dorgqr(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    double *            a,
    lapack_int            lda,
    const double *            tau
)
{
    if(_g_LAPACKE_dorgqr==NULL) {
        _g_LAPACKE_dorgqr = rindow_load_libopenblas_func("LAPACKE_dorgqr"); 
        if(_g_LAPACKE_dorgqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dorgqr(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}

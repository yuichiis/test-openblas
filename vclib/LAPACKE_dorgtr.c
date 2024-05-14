#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dorgtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dorgtr)( /* LAPACKE_dorgtr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */
);
static PFNLAPACKE_dorgtr _g_LAPACKE_dorgtr = NULL;
lapack_int LAPACKE_dorgtr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    const double *            tau
)
{
    if(_g_LAPACKE_dorgtr==NULL) {
        _g_LAPACKE_dorgtr = rindow_load_libopenblas_func("LAPACKE_dorgtr"); 
        if(_g_LAPACKE_dorgtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dorgtr(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        tau    
    );
}

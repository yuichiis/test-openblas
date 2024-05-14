#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dopmtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dopmtr)( /* LAPACKE_dopmtr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* ap */,
    const double *            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_dopmtr _g_LAPACKE_dopmtr = NULL;
lapack_int LAPACKE_dopmtr(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const double *            ap,
    const double *            tau,
    double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_dopmtr==NULL) {
        _g_LAPACKE_dopmtr = rindow_load_libopenblas_func("LAPACKE_dopmtr"); 
        if(_g_LAPACKE_dopmtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dopmtr(
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

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dopgtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dopgtr)( /* LAPACKE_dopgtr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* ap */,
    const double *            /* tau */,
    double *            /* q */,
    lapack_int            /* ldq */
);
static PFNLAPACKE_dopgtr _g_LAPACKE_dopgtr = NULL;
lapack_int LAPACKE_dopgtr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            ap,
    const double *            tau,
    double *            q,
    lapack_int            ldq
)
{
    if(_g_LAPACKE_dopgtr==NULL) {
        _g_LAPACKE_dopgtr = rindow_load_libopenblas_func("LAPACKE_dopgtr"); 
        if(_g_LAPACKE_dopgtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dopgtr(
        matrix_layout,
        uplo,
        n,
        ap,
        tau,
        q,
        ldq    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsptrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsptrd)( /* LAPACKE_dsptrd */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    double *            /* d */,
    double *            /* e */,
    double *            /* tau */
);
static PFNLAPACKE_dsptrd _g_LAPACKE_dsptrd = NULL;
lapack_int LAPACKE_dsptrd(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            ap,
    double *            d,
    double *            e,
    double *            tau
)
{
    if(_g_LAPACKE_dsptrd==NULL) {
        _g_LAPACKE_dsptrd = rindow_load_libopenblas_func("LAPACKE_dsptrd"); 
        if(_g_LAPACKE_dsptrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsptrd(
        matrix_layout,
        uplo,
        n,
        ap,
        d,
        e,
        tau    
    );
}

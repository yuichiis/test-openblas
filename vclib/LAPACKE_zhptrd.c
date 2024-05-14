#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhptrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhptrd)( /* LAPACKE_zhptrd */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    double *            /* d */,
    double *            /* e */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zhptrd _g_LAPACKE_zhptrd = NULL;
lapack_int LAPACKE_zhptrd(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    double *            d,
    double *            e,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zhptrd==NULL) {
        _g_LAPACKE_zhptrd = rindow_load_libopenblas_func("LAPACKE_zhptrd"); 
        if(_g_LAPACKE_zhptrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhptrd(
        matrix_layout,
        uplo,
        n,
        ap,
        d,
        e,
        tau    
    );
}

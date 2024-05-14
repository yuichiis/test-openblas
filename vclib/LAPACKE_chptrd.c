#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chptrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chptrd)( /* LAPACKE_chptrd */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    float *            /* d */,
    float *            /* e */,
    lapack_complex_float *            /* tau */
);
static PFNLAPACKE_chptrd _g_LAPACKE_chptrd = NULL;
lapack_int LAPACKE_chptrd(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    float *            d,
    float *            e,
    lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_chptrd==NULL) {
        _g_LAPACKE_chptrd = rindow_load_libopenblas_func("LAPACKE_chptrd"); 
        if(_g_LAPACKE_chptrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chptrd(
        matrix_layout,
        uplo,
        n,
        ap,
        d,
        e,
        tau    
    );
}

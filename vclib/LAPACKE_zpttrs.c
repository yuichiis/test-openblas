#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpttrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpttrs)( /* LAPACKE_zpttrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* d */,
    const lapack_complex_double *            /* e */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zpttrs _g_LAPACKE_zpttrs = NULL;
lapack_int LAPACKE_zpttrs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            d,
    const lapack_complex_double *            e,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zpttrs==NULL) {
        _g_LAPACKE_zpttrs = rindow_load_libopenblas_func("LAPACKE_zpttrs"); 
        if(_g_LAPACKE_zpttrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpttrs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        d,
        e,
        b,
        ldb    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssptrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssptrs)( /* LAPACKE_ssptrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* ap */,
    const lapack_int *            /* ipiv */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_ssptrs _g_LAPACKE_ssptrs = NULL;
lapack_int LAPACKE_ssptrs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            ap,
    const lapack_int *            ipiv,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_ssptrs==NULL) {
        _g_LAPACKE_ssptrs = rindow_load_libopenblas_func("LAPACKE_ssptrs"); 
        if(_g_LAPACKE_ssptrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssptrs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        ipiv,
        b,
        ldb    
    );
}

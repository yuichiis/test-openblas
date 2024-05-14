#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csptrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csptrs)( /* LAPACKE_csptrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ap */,
    const lapack_int *            /* ipiv */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_csptrs _g_LAPACKE_csptrs = NULL;
lapack_int LAPACKE_csptrs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            ap,
    const lapack_int *            ipiv,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_csptrs==NULL) {
        _g_LAPACKE_csptrs = rindow_load_libopenblas_func("LAPACKE_csptrs"); 
        if(_g_LAPACKE_csptrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csptrs(
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

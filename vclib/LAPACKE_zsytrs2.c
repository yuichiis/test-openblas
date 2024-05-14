#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsytrs2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsytrs2)( /* LAPACKE_zsytrs2 */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zsytrs2 _g_LAPACKE_zsytrs2 = NULL;
lapack_int LAPACKE_zsytrs2(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zsytrs2==NULL) {
        _g_LAPACKE_zsytrs2 = rindow_load_libopenblas_func("LAPACKE_zsytrs2"); 
        if(_g_LAPACKE_zsytrs2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsytrs2(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        ipiv,
        b,
        ldb    
    );
}

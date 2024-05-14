#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csysv_rk not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csysv_rk)( /* LAPACKE_csysv_rk */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* e */,
    lapack_int *            /* ipiv */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_csysv_rk _g_LAPACKE_csysv_rk = NULL;
lapack_int LAPACKE_csysv_rk(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            e,
    lapack_int *            ipiv,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_csysv_rk==NULL) {
        _g_LAPACKE_csysv_rk = rindow_load_libopenblas_func("LAPACKE_csysv_rk"); 
        if(_g_LAPACKE_csysv_rk==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csysv_rk(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        e,
        ipiv,
        b,
        ldb    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chetrf_rk not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chetrf_rk)( /* LAPACKE_chetrf_rk */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* e */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_chetrf_rk _g_LAPACKE_chetrf_rk = NULL;
lapack_int LAPACKE_chetrf_rk(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            e,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_chetrf_rk==NULL) {
        _g_LAPACKE_chetrf_rk = rindow_load_libopenblas_func("LAPACKE_chetrf_rk"); 
        if(_g_LAPACKE_chetrf_rk==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chetrf_rk(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        e,
        ipiv    
    );
}

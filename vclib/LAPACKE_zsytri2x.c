#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsytri2x not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsytri2x)( /* LAPACKE_zsytri2x */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_int            /* nb */
);
static PFNLAPACKE_zsytri2x _g_LAPACKE_zsytri2x = NULL;
lapack_int LAPACKE_zsytri2x(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    lapack_int            nb
)
{
    if(_g_LAPACKE_zsytri2x==NULL) {
        _g_LAPACKE_zsytri2x = rindow_load_libopenblas_func("LAPACKE_zsytri2x"); 
        if(_g_LAPACKE_zsytri2x==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsytri2x(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv,
        nb    
    );
}

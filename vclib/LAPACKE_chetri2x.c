#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chetri2x not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chetri2x)( /* LAPACKE_chetri2x */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_int            /* nb */
);
static PFNLAPACKE_chetri2x _g_LAPACKE_chetri2x = NULL;
lapack_int LAPACKE_chetri2x(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    lapack_int            nb
)
{
    if(_g_LAPACKE_chetri2x==NULL) {
        _g_LAPACKE_chetri2x = rindow_load_libopenblas_func("LAPACKE_chetri2x"); 
        if(_g_LAPACKE_chetri2x==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chetri2x(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv,
        nb    
    );
}

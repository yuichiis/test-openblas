#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhetri2x not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhetri2x)( /* LAPACKE_zhetri2x */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_int            /* nb */
);
static PFNLAPACKE_zhetri2x _g_LAPACKE_zhetri2x = NULL;
lapack_int LAPACKE_zhetri2x(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    lapack_int            nb
)
{
    if(_g_LAPACKE_zhetri2x==NULL) {
        _g_LAPACKE_zhetri2x = rindow_load_libopenblas_func("LAPACKE_zhetri2x"); 
        if(_g_LAPACKE_zhetri2x==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhetri2x(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv,
        nb    
    );
}

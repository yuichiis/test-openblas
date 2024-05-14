#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsyconv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsyconv)( /* LAPACKE_zsyconv */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* way */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_complex_double *            /* e */
);
static PFNLAPACKE_zsyconv _g_LAPACKE_zsyconv = NULL;
lapack_int LAPACKE_zsyconv(
    int            matrix_layout,
    char            uplo,
    char            way,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    lapack_complex_double *            e
)
{
    if(_g_LAPACKE_zsyconv==NULL) {
        _g_LAPACKE_zsyconv = rindow_load_libopenblas_func("LAPACKE_zsyconv"); 
        if(_g_LAPACKE_zsyconv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsyconv(
        matrix_layout,
        uplo,
        way,
        n,
        a,
        lda,
        ipiv,
        e    
    );
}

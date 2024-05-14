#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsyconv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsyconv_work)( /* LAPACKE_zsyconv_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* way */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_complex_double *            /* e */
);
static PFNLAPACKE_zsyconv_work _g_LAPACKE_zsyconv_work = NULL;
lapack_int LAPACKE_zsyconv_work(
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
    if(_g_LAPACKE_zsyconv_work==NULL) {
        _g_LAPACKE_zsyconv_work = rindow_load_libopenblas_func("LAPACKE_zsyconv_work"); 
        if(_g_LAPACKE_zsyconv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsyconv_work(
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

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slacpy not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slacpy)( /* LAPACKE_slacpy */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_slacpy _g_LAPACKE_slacpy = NULL;
lapack_int LAPACKE_slacpy(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_slacpy==NULL) {
        _g_LAPACKE_slacpy = rindow_load_libopenblas_func("LAPACKE_slacpy"); 
        if(_g_LAPACKE_slacpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slacpy(
        matrix_layout,
        uplo,
        m,
        n,
        a,
        lda,
        b,
        ldb    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlacpy not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlacpy)( /* LAPACKE_zlacpy */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zlacpy _g_LAPACKE_zlacpy = NULL;
lapack_int LAPACKE_zlacpy(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zlacpy==NULL) {
        _g_LAPACKE_zlacpy = rindow_load_libopenblas_func("LAPACKE_zlacpy"); 
        if(_g_LAPACKE_zlacpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlacpy(
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

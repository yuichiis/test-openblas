#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlacpy not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlacpy)( /* LAPACKE_dlacpy */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dlacpy _g_LAPACKE_dlacpy = NULL;
lapack_int LAPACKE_dlacpy(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dlacpy==NULL) {
        _g_LAPACKE_dlacpy = rindow_load_libopenblas_func("LAPACKE_dlacpy"); 
        if(_g_LAPACKE_dlacpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlacpy(
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

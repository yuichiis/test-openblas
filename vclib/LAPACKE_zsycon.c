#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsycon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsycon)( /* LAPACKE_zsycon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zsycon _g_LAPACKE_zsycon = NULL;
lapack_int LAPACKE_zsycon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zsycon==NULL) {
        _g_LAPACKE_zsycon = rindow_load_libopenblas_func("LAPACKE_zsycon"); 
        if(_g_LAPACKE_zsycon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsycon(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv,
        anorm,
        rcond    
    );
}

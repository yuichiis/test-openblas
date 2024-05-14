#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsycon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsycon)( /* LAPACKE_dsycon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dsycon _g_LAPACKE_dsycon = NULL;
lapack_int LAPACKE_dsycon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dsycon==NULL) {
        _g_LAPACKE_dsycon = rindow_load_libopenblas_func("LAPACKE_dsycon"); 
        if(_g_LAPACKE_dsycon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsycon(
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

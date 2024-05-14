#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssycon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssycon)( /* LAPACKE_ssycon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_ssycon _g_LAPACKE_ssycon = NULL;
lapack_int LAPACKE_ssycon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_ssycon==NULL) {
        _g_LAPACKE_ssycon = rindow_load_libopenblas_func("LAPACKE_ssycon"); 
        if(_g_LAPACKE_ssycon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssycon(
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

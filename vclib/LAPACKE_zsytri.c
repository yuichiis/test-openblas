#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsytri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsytri)( /* LAPACKE_zsytri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_zsytri _g_LAPACKE_zsytri = NULL;
lapack_int LAPACKE_zsytri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zsytri==NULL) {
        _g_LAPACKE_zsytri = rindow_load_libopenblas_func("LAPACKE_zsytri"); 
        if(_g_LAPACKE_zsytri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsytri(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

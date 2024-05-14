#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsytri_3 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsytri_3)( /* LAPACKE_zsytri_3 */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* e */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_zsytri_3 _g_LAPACKE_zsytri_3 = NULL;
lapack_int LAPACKE_zsytri_3(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            e,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zsytri_3==NULL) {
        _g_LAPACKE_zsytri_3 = rindow_load_libopenblas_func("LAPACKE_zsytri_3"); 
        if(_g_LAPACKE_zsytri_3==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsytri_3(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        e,
        ipiv    
    );
}

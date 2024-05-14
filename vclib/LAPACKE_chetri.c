#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chetri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chetri)( /* LAPACKE_chetri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_chetri _g_LAPACKE_chetri = NULL;
lapack_int LAPACKE_chetri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_chetri==NULL) {
        _g_LAPACKE_chetri = rindow_load_libopenblas_func("LAPACKE_chetri"); 
        if(_g_LAPACKE_chetri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chetri(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

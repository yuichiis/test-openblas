#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csytri2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csytri2)( /* LAPACKE_csytri2 */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_csytri2 _g_LAPACKE_csytri2 = NULL;
lapack_int LAPACKE_csytri2(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_csytri2==NULL) {
        _g_LAPACKE_csytri2 = rindow_load_libopenblas_func("LAPACKE_csytri2"); 
        if(_g_LAPACKE_csytri2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csytri2(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

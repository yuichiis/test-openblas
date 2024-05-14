#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csytrf_rook not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csytrf_rook)( /* LAPACKE_csytrf_rook */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_csytrf_rook _g_LAPACKE_csytrf_rook = NULL;
lapack_int LAPACKE_csytrf_rook(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_csytrf_rook==NULL) {
        _g_LAPACKE_csytrf_rook = rindow_load_libopenblas_func("LAPACKE_csytrf_rook"); 
        if(_g_LAPACKE_csytrf_rook==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csytrf_rook(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chetrf_rook not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chetrf_rook)( /* LAPACKE_chetrf_rook */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_chetrf_rook _g_LAPACKE_chetrf_rook = NULL;
lapack_int LAPACKE_chetrf_rook(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_chetrf_rook==NULL) {
        _g_LAPACKE_chetrf_rook = rindow_load_libopenblas_func("LAPACKE_chetrf_rook"); 
        if(_g_LAPACKE_chetrf_rook==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chetrf_rook(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

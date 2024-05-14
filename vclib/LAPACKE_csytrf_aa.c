#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csytrf_aa not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csytrf_aa)( /* LAPACKE_csytrf_aa */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_csytrf_aa _g_LAPACKE_csytrf_aa = NULL;
lapack_int LAPACKE_csytrf_aa(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_csytrf_aa==NULL) {
        _g_LAPACKE_csytrf_aa = rindow_load_libopenblas_func("LAPACKE_csytrf_aa"); 
        if(_g_LAPACKE_csytrf_aa==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csytrf_aa(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csytrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csytrf)( /* LAPACKE_csytrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_csytrf _g_LAPACKE_csytrf = NULL;
lapack_int LAPACKE_csytrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_csytrf==NULL) {
        _g_LAPACKE_csytrf = rindow_load_libopenblas_func("LAPACKE_csytrf"); 
        if(_g_LAPACKE_csytrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csytrf(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

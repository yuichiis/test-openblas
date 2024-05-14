#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssytrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssytrf)( /* LAPACKE_ssytrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_ssytrf _g_LAPACKE_ssytrf = NULL;
lapack_int LAPACKE_ssytrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_ssytrf==NULL) {
        _g_LAPACKE_ssytrf = rindow_load_libopenblas_func("LAPACKE_ssytrf"); 
        if(_g_LAPACKE_ssytrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssytrf(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

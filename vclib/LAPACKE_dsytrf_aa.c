#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsytrf_aa not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsytrf_aa)( /* LAPACKE_dsytrf_aa */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_dsytrf_aa _g_LAPACKE_dsytrf_aa = NULL;
lapack_int LAPACKE_dsytrf_aa(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_dsytrf_aa==NULL) {
        _g_LAPACKE_dsytrf_aa = rindow_load_libopenblas_func("LAPACKE_dsytrf_aa"); 
        if(_g_LAPACKE_dsytrf_aa==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsytrf_aa(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv    
    );
}

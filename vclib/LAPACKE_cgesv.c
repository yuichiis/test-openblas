#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgesv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgesv)( /* LAPACKE_cgesv */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cgesv _g_LAPACKE_cgesv = NULL;
lapack_int LAPACKE_cgesv(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            ipiv,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cgesv==NULL) {
        _g_LAPACKE_cgesv = rindow_load_libopenblas_func("LAPACKE_cgesv"); 
        if(_g_LAPACKE_cgesv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgesv(
        matrix_layout,
        n,
        nrhs,
        a,
        lda,
        ipiv,
        b,
        ldb    
    );
}

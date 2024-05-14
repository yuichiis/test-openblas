#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesv)( /* LAPACKE_sgesv */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sgesv _g_LAPACKE_sgesv = NULL;
lapack_int LAPACKE_sgesv(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    float *            a,
    lapack_int            lda,
    lapack_int *            ipiv,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sgesv==NULL) {
        _g_LAPACKE_sgesv = rindow_load_libopenblas_func("LAPACKE_sgesv"); 
        if(_g_LAPACKE_sgesv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesv(
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

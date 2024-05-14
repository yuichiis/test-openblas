#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsyconv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsyconv)( /* LAPACKE_dsyconv */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* way */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    double *            /* e */
);
static PFNLAPACKE_dsyconv _g_LAPACKE_dsyconv = NULL;
lapack_int LAPACKE_dsyconv(
    int            matrix_layout,
    char            uplo,
    char            way,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    double *            e
)
{
    if(_g_LAPACKE_dsyconv==NULL) {
        _g_LAPACKE_dsyconv = rindow_load_libopenblas_func("LAPACKE_dsyconv"); 
        if(_g_LAPACKE_dsyconv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsyconv(
        matrix_layout,
        uplo,
        way,
        n,
        a,
        lda,
        ipiv,
        e    
    );
}

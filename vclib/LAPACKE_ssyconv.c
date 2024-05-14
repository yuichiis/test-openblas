#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssyconv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssyconv)( /* LAPACKE_ssyconv */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* way */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    float *            /* e */
);
static PFNLAPACKE_ssyconv _g_LAPACKE_ssyconv = NULL;
lapack_int LAPACKE_ssyconv(
    int            matrix_layout,
    char            uplo,
    char            way,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    float *            e
)
{
    if(_g_LAPACKE_ssyconv==NULL) {
        _g_LAPACKE_ssyconv = rindow_load_libopenblas_func("LAPACKE_ssyconv"); 
        if(_g_LAPACKE_ssyconv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssyconv(
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

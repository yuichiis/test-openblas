#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgetrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgetrs)( /* LAPACKE_cgetrs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cgetrs _g_LAPACKE_cgetrs = NULL;
lapack_int LAPACKE_cgetrs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cgetrs==NULL) {
        _g_LAPACKE_cgetrs = rindow_load_libopenblas_func("LAPACKE_cgetrs"); 
        if(_g_LAPACKE_cgetrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgetrs(
        matrix_layout,
        trans,
        n,
        nrhs,
        a,
        lda,
        ipiv,
        b,
        ldb    
    );
}

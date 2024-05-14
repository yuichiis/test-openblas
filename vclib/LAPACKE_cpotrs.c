#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpotrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpotrs)( /* LAPACKE_cpotrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cpotrs _g_LAPACKE_cpotrs = NULL;
lapack_int LAPACKE_cpotrs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cpotrs==NULL) {
        _g_LAPACKE_cpotrs = rindow_load_libopenblas_func("LAPACKE_cpotrs"); 
        if(_g_LAPACKE_cpotrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpotrs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb    
    );
}

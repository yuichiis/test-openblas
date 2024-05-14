#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zspsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zspsv)( /* LAPACKE_zspsv */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* ap */,
    lapack_int *            /* ipiv */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zspsv _g_LAPACKE_zspsv = NULL;
lapack_int LAPACKE_zspsv(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            ap,
    lapack_int *            ipiv,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zspsv==NULL) {
        _g_LAPACKE_zspsv = rindow_load_libopenblas_func("LAPACKE_zspsv"); 
        if(_g_LAPACKE_zspsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zspsv(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        ipiv,
        b,
        ldb    
    );
}

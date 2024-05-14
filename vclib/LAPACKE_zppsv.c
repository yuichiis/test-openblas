#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zppsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zppsv)( /* LAPACKE_zppsv */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* ap */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zppsv _g_LAPACKE_zppsv = NULL;
lapack_int LAPACKE_zppsv(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            ap,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zppsv==NULL) {
        _g_LAPACKE_zppsv = rindow_load_libopenblas_func("LAPACKE_zppsv"); 
        if(_g_LAPACKE_zppsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zppsv(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        b,
        ldb    
    );
}

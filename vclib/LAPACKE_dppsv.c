#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dppsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dppsv)( /* LAPACKE_dppsv */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* ap */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dppsv _g_LAPACKE_dppsv = NULL;
lapack_int LAPACKE_dppsv(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    double *            ap,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dppsv==NULL) {
        _g_LAPACKE_dppsv = rindow_load_libopenblas_func("LAPACKE_dppsv"); 
        if(_g_LAPACKE_dppsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dppsv(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        b,
        ldb    
    );
}

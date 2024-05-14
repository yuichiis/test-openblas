#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsprfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsprfs)( /* LAPACKE_dsprfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* ap */,
    const double *            /* afp */,
    const lapack_int *            /* ipiv */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_dsprfs _g_LAPACKE_dsprfs = NULL;
lapack_int LAPACKE_dsprfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            ap,
    const double *            afp,
    const lapack_int *            ipiv,
    const double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_dsprfs==NULL) {
        _g_LAPACKE_dsprfs = rindow_load_libopenblas_func("LAPACKE_dsprfs"); 
        if(_g_LAPACKE_dsprfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsprfs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        afp,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}

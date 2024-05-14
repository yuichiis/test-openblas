#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zptrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zptrfs_work)( /* LAPACKE_zptrfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* d */,
    const lapack_complex_double *            /* e */,
    const double *            /* df */,
    const lapack_complex_double *            /* ef */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zptrfs_work _g_LAPACKE_zptrfs_work = NULL;
lapack_int LAPACKE_zptrfs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            d,
    const lapack_complex_double *            e,
    const double *            df,
    const lapack_complex_double *            ef,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zptrfs_work==NULL) {
        _g_LAPACKE_zptrfs_work = rindow_load_libopenblas_func("LAPACKE_zptrfs_work"); 
        if(_g_LAPACKE_zptrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zptrfs_work(
        matrix_layout,
        uplo,
        n,
        nrhs,
        d,
        e,
        df,
        ef,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr,
        work,
        rwork    
    );
}

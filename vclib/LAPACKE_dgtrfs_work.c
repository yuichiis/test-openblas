#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgtrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgtrfs_work)( /* LAPACKE_dgtrfs_work */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* dl */,
    const double *            /* d */,
    const double *            /* du */,
    const double *            /* dlf */,
    const double *            /* df */,
    const double *            /* duf */,
    const double *            /* du2 */,
    const lapack_int *            /* ipiv */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dgtrfs_work _g_LAPACKE_dgtrfs_work = NULL;
lapack_int LAPACKE_dgtrfs_work(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            dl,
    const double *            d,
    const double *            du,
    const double *            dlf,
    const double *            df,
    const double *            duf,
    const double *            du2,
    const lapack_int *            ipiv,
    const double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dgtrfs_work==NULL) {
        _g_LAPACKE_dgtrfs_work = rindow_load_libopenblas_func("LAPACKE_dgtrfs_work"); 
        if(_g_LAPACKE_dgtrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgtrfs_work(
        matrix_layout,
        trans,
        n,
        nrhs,
        dl,
        d,
        du,
        dlf,
        df,
        duf,
        du2,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr,
        work,
        iwork    
    );
}

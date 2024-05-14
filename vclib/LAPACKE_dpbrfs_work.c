#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpbrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpbrfs_work)( /* LAPACKE_dpbrfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    const double *            /* afb */,
    lapack_int            /* ldafb */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dpbrfs_work _g_LAPACKE_dpbrfs_work = NULL;
lapack_int LAPACKE_dpbrfs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const double *            ab,
    lapack_int            ldab,
    const double *            afb,
    lapack_int            ldafb,
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
    if(_g_LAPACKE_dpbrfs_work==NULL) {
        _g_LAPACKE_dpbrfs_work = rindow_load_libopenblas_func("LAPACKE_dpbrfs_work"); 
        if(_g_LAPACKE_dpbrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpbrfs_work(
        matrix_layout,
        uplo,
        n,
        kd,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
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

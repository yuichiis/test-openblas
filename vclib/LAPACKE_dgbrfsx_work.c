#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgbrfsx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgbrfsx_work)( /* LAPACKE_dgbrfsx_work */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* equed */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    const double *            /* afb */,
    lapack_int            /* ldafb */,
    const lapack_int *            /* ipiv */,
    const double *            /* r */,
    const double *            /* c */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* berr */,
    lapack_int            /* n_err_bnds */,
    double *            /* err_bnds_norm */,
    double *            /* err_bnds_comp */,
    lapack_int            /* nparams */,
    double *            /* params */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dgbrfsx_work _g_LAPACKE_dgbrfsx_work = NULL;
lapack_int LAPACKE_dgbrfsx_work(
    int            matrix_layout,
    char            trans,
    char            equed,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    const double *            ab,
    lapack_int            ldab,
    const double *            afb,
    lapack_int            ldafb,
    const lapack_int *            ipiv,
    const double *            r,
    const double *            c,
    const double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            berr,
    lapack_int            n_err_bnds,
    double *            err_bnds_norm,
    double *            err_bnds_comp,
    lapack_int            nparams,
    double *            params,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dgbrfsx_work==NULL) {
        _g_LAPACKE_dgbrfsx_work = rindow_load_libopenblas_func("LAPACKE_dgbrfsx_work"); 
        if(_g_LAPACKE_dgbrfsx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgbrfsx_work(
        matrix_layout,
        trans,
        equed,
        n,
        kl,
        ku,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
        ipiv,
        r,
        c,
        b,
        ldb,
        x,
        ldx,
        rcond,
        berr,
        n_err_bnds,
        err_bnds_norm,
        err_bnds_comp,
        nparams,
        params,
        work,
        iwork    
    );
}

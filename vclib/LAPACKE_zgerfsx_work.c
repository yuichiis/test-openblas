#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgerfsx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgerfsx_work)( /* LAPACKE_zgerfsx_work */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* equed */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* af */,
    lapack_int            /* ldaf */,
    const lapack_int *            /* ipiv */,
    const double *            /* r */,
    const double *            /* c */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* berr */,
    lapack_int            /* n_err_bnds */,
    double *            /* err_bnds_norm */,
    double *            /* err_bnds_comp */,
    lapack_int            /* nparams */,
    double *            /* params */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zgerfsx_work _g_LAPACKE_zgerfsx_work = NULL;
lapack_int LAPACKE_zgerfsx_work(
    int            matrix_layout,
    char            trans,
    char            equed,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            af,
    lapack_int            ldaf,
    const lapack_int *            ipiv,
    const double *            r,
    const double *            c,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            berr,
    lapack_int            n_err_bnds,
    double *            err_bnds_norm,
    double *            err_bnds_comp,
    lapack_int            nparams,
    double *            params,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zgerfsx_work==NULL) {
        _g_LAPACKE_zgerfsx_work = rindow_load_libopenblas_func("LAPACKE_zgerfsx_work"); 
        if(_g_LAPACKE_zgerfsx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgerfsx_work(
        matrix_layout,
        trans,
        equed,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
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
        rwork    
    );
}

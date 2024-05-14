#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsysvxx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsysvxx_work)( /* LAPACKE_dsysvxx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* af */,
    lapack_int            /* ldaf */,
    lapack_int *            /* ipiv */,
    char *            /* equed */,
    double *            /* s */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* rpvgrw */,
    double *            /* berr */,
    lapack_int            /* n_err_bnds */,
    double *            /* err_bnds_norm */,
    double *            /* err_bnds_comp */,
    lapack_int            /* nparams */,
    double *            /* params */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dsysvxx_work _g_LAPACKE_dsysvxx_work = NULL;
lapack_int LAPACKE_dsysvxx_work(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    double *            a,
    lapack_int            lda,
    double *            af,
    lapack_int            ldaf,
    lapack_int *            ipiv,
    char *            equed,
    double *            s,
    double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            rpvgrw,
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
    if(_g_LAPACKE_dsysvxx_work==NULL) {
        _g_LAPACKE_dsysvxx_work = rindow_load_libopenblas_func("LAPACKE_dsysvxx_work"); 
        if(_g_LAPACKE_dsysvxx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsysvxx_work(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
        ipiv,
        equed,
        s,
        b,
        ldb,
        x,
        ldx,
        rcond,
        rpvgrw,
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

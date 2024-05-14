#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgesvxx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgesvxx)( /* LAPACKE_dgesvxx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* af */,
    lapack_int            /* ldaf */,
    lapack_int *            /* ipiv */,
    char *            /* equed */,
    double *            /* r */,
    double *            /* c */,
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
    double *            /* params */
);
static PFNLAPACKE_dgesvxx _g_LAPACKE_dgesvxx = NULL;
lapack_int LAPACKE_dgesvxx(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    double *            a,
    lapack_int            lda,
    double *            af,
    lapack_int            ldaf,
    lapack_int *            ipiv,
    char *            equed,
    double *            r,
    double *            c,
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
    double *            params
)
{
    if(_g_LAPACKE_dgesvxx==NULL) {
        _g_LAPACKE_dgesvxx = rindow_load_libopenblas_func("LAPACKE_dgesvxx"); 
        if(_g_LAPACKE_dgesvxx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgesvxx(
        matrix_layout,
        fact,
        trans,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
        ipiv,
        equed,
        r,
        c,
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
        params    
    );
}

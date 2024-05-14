#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgerfsx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgerfsx)( /* LAPACKE_dgerfsx */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* equed */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* af */,
    lapack_int            /* ldaf */,
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
    double *            /* params */
);
static PFNLAPACKE_dgerfsx _g_LAPACKE_dgerfsx = NULL;
lapack_int LAPACKE_dgerfsx(
    int            matrix_layout,
    char            trans,
    char            equed,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            a,
    lapack_int            lda,
    const double *            af,
    lapack_int            ldaf,
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
    double *            params
)
{
    if(_g_LAPACKE_dgerfsx==NULL) {
        _g_LAPACKE_dgerfsx = rindow_load_libopenblas_func("LAPACKE_dgerfsx"); 
        if(_g_LAPACKE_dgerfsx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgerfsx(
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
        params    
    );
}

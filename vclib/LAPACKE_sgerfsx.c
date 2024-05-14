#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgerfsx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgerfsx)( /* LAPACKE_sgerfsx */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* equed */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* af */,
    lapack_int            /* ldaf */,
    const lapack_int *            /* ipiv */,
    const float *            /* r */,
    const float *            /* c */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* berr */,
    lapack_int            /* n_err_bnds */,
    float *            /* err_bnds_norm */,
    float *            /* err_bnds_comp */,
    lapack_int            /* nparams */,
    float *            /* params */
);
static PFNLAPACKE_sgerfsx _g_LAPACKE_sgerfsx = NULL;
lapack_int LAPACKE_sgerfsx(
    int            matrix_layout,
    char            trans,
    char            equed,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            a,
    lapack_int            lda,
    const float *            af,
    lapack_int            ldaf,
    const lapack_int *            ipiv,
    const float *            r,
    const float *            c,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            berr,
    lapack_int            n_err_bnds,
    float *            err_bnds_norm,
    float *            err_bnds_comp,
    lapack_int            nparams,
    float *            params
)
{
    if(_g_LAPACKE_sgerfsx==NULL) {
        _g_LAPACKE_sgerfsx = rindow_load_libopenblas_func("LAPACKE_sgerfsx"); 
        if(_g_LAPACKE_sgerfsx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgerfsx(
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

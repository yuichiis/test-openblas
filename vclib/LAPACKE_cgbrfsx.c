#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgbrfsx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgbrfsx)( /* LAPACKE_cgbrfsx */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* equed */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_complex_float *            /* afb */,
    lapack_int            /* ldafb */,
    const lapack_int *            /* ipiv */,
    const float *            /* r */,
    const float *            /* c */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* berr */,
    lapack_int            /* n_err_bnds */,
    float *            /* err_bnds_norm */,
    float *            /* err_bnds_comp */,
    lapack_int            /* nparams */,
    float *            /* params */
);
static PFNLAPACKE_cgbrfsx _g_LAPACKE_cgbrfsx = NULL;
lapack_int LAPACKE_cgbrfsx(
    int            matrix_layout,
    char            trans,
    char            equed,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    const lapack_complex_float *            afb,
    lapack_int            ldafb,
    const lapack_int *            ipiv,
    const float *            r,
    const float *            c,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
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
    if(_g_LAPACKE_cgbrfsx==NULL) {
        _g_LAPACKE_cgbrfsx = rindow_load_libopenblas_func("LAPACKE_cgbrfsx"); 
        if(_g_LAPACKE_cgbrfsx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgbrfsx(
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
        params    
    );
}

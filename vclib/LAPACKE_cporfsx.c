#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cporfsx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cporfsx)( /* LAPACKE_cporfsx */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* equed */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* af */,
    lapack_int            /* ldaf */,
    const float *            /* s */,
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
static PFNLAPACKE_cporfsx _g_LAPACKE_cporfsx = NULL;
lapack_int LAPACKE_cporfsx(
    int            matrix_layout,
    char            uplo,
    char            equed,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            af,
    lapack_int            ldaf,
    const float *            s,
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
    if(_g_LAPACKE_cporfsx==NULL) {
        _g_LAPACKE_cporfsx = rindow_load_libopenblas_func("LAPACKE_cporfsx"); 
        if(_g_LAPACKE_cporfsx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cporfsx(
        matrix_layout,
        uplo,
        equed,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
        s,
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

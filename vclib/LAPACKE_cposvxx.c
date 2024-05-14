#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cposvxx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cposvxx)( /* LAPACKE_cposvxx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* af */,
    lapack_int            /* ldaf */,
    char *            /* equed */,
    float *            /* s */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* rpvgrw */,
    float *            /* berr */,
    lapack_int            /* n_err_bnds */,
    float *            /* err_bnds_norm */,
    float *            /* err_bnds_comp */,
    lapack_int            /* nparams */,
    float *            /* params */
);
static PFNLAPACKE_cposvxx _g_LAPACKE_cposvxx = NULL;
lapack_int LAPACKE_cposvxx(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            af,
    lapack_int            ldaf,
    char *            equed,
    float *            s,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            rpvgrw,
    float *            berr,
    lapack_int            n_err_bnds,
    float *            err_bnds_norm,
    float *            err_bnds_comp,
    lapack_int            nparams,
    float *            params
)
{
    if(_g_LAPACKE_cposvxx==NULL) {
        _g_LAPACKE_cposvxx = rindow_load_libopenblas_func("LAPACKE_cposvxx"); 
        if(_g_LAPACKE_cposvxx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cposvxx(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
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
        params    
    );
}

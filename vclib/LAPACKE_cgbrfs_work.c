#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgbrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgbrfs_work)( /* LAPACKE_cgbrfs_work */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_complex_float *            /* afb */,
    lapack_int            /* ldafb */,
    const lapack_int *            /* ipiv */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_cgbrfs_work _g_LAPACKE_cgbrfs_work = NULL;
lapack_int LAPACKE_cgbrfs_work(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    const lapack_complex_float *            afb,
    lapack_int            ldafb,
    const lapack_int *            ipiv,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_cgbrfs_work==NULL) {
        _g_LAPACKE_cgbrfs_work = rindow_load_libopenblas_func("LAPACKE_cgbrfs_work"); 
        if(_g_LAPACKE_cgbrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgbrfs_work(
        matrix_layout,
        trans,
        n,
        kl,
        ku,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr,
        work,
        rwork    
    );
}

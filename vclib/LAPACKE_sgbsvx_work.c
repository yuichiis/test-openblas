#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgbsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgbsvx_work)( /* LAPACKE_sgbsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* afb */,
    lapack_int            /* ldafb */,
    lapack_int *            /* ipiv */,
    char *            /* equed */,
    float *            /* r */,
    float *            /* c */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sgbsvx_work _g_LAPACKE_sgbsvx_work = NULL;
lapack_int LAPACKE_sgbsvx_work(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    float *            ab,
    lapack_int            ldab,
    float *            afb,
    lapack_int            ldafb,
    lapack_int *            ipiv,
    char *            equed,
    float *            r,
    float *            c,
    float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_sgbsvx_work==NULL) {
        _g_LAPACKE_sgbsvx_work = rindow_load_libopenblas_func("LAPACKE_sgbsvx_work"); 
        if(_g_LAPACKE_sgbsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgbsvx_work(
        matrix_layout,
        fact,
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
        equed,
        r,
        c,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr,
        work,
        iwork    
    );
}

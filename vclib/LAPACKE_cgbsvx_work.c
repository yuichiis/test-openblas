#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgbsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgbsvx_work)( /* LAPACKE_cgbsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_float *            /* afb */,
    lapack_int            /* ldafb */,
    lapack_int *            /* ipiv */,
    char *            /* equed */,
    float *            /* r */,
    float *            /* c */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_cgbsvx_work _g_LAPACKE_cgbsvx_work = NULL;
lapack_int LAPACKE_cgbsvx_work(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    lapack_complex_float *            afb,
    lapack_int            ldafb,
    lapack_int *            ipiv,
    char *            equed,
    float *            r,
    float *            c,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_cgbsvx_work==NULL) {
        _g_LAPACKE_cgbsvx_work = rindow_load_libopenblas_func("LAPACKE_cgbsvx_work"); 
        if(_g_LAPACKE_cgbsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgbsvx_work(
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
        rwork    
    );
}

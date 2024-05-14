#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggevx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggevx_work)( /* LAPACKE_cggevx_work */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* alpha */,
    lapack_complex_float *            /* beta */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* lscale */,
    float *            /* rscale */,
    float *            /* abnrm */,
    float *            /* bbnrm */,
    float *            /* rconde */,
    float *            /* rcondv */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_int *            /* iwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_cggevx_work _g_LAPACKE_cggevx_work = NULL;
lapack_int LAPACKE_cggevx_work(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            alpha,
    lapack_complex_float *            beta,
    lapack_complex_float *            vl,
    lapack_int            ldvl,
    lapack_complex_float *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            lscale,
    float *            rscale,
    float *            abnrm,
    float *            bbnrm,
    float *            rconde,
    float *            rcondv,
    lapack_complex_float *            work,
    lapack_int            lwork,
    float *            rwork,
    lapack_int *            iwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_cggevx_work==NULL) {
        _g_LAPACKE_cggevx_work = rindow_load_libopenblas_func("LAPACKE_cggevx_work"); 
        if(_g_LAPACKE_cggevx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggevx_work(
        matrix_layout,
        balanc,
        jobvl,
        jobvr,
        sense,
        n,
        a,
        lda,
        b,
        ldb,
        alpha,
        beta,
        vl,
        ldvl,
        vr,
        ldvr,
        ilo,
        ihi,
        lscale,
        rscale,
        abnrm,
        bbnrm,
        rconde,
        rcondv,
        work,
        lwork,
        rwork,
        iwork,
        bwork    
    );
}

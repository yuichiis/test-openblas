#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zggevx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zggevx_work)( /* LAPACKE_zggevx_work */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* alpha */,
    lapack_complex_double *            /* beta */,
    lapack_complex_double *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* lscale */,
    double *            /* rscale */,
    double *            /* abnrm */,
    double *            /* bbnrm */,
    double *            /* rconde */,
    double *            /* rcondv */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    double *            /* rwork */,
    lapack_int *            /* iwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_zggevx_work _g_LAPACKE_zggevx_work = NULL;
lapack_int LAPACKE_zggevx_work(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            alpha,
    lapack_complex_double *            beta,
    lapack_complex_double *            vl,
    lapack_int            ldvl,
    lapack_complex_double *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            lscale,
    double *            rscale,
    double *            abnrm,
    double *            bbnrm,
    double *            rconde,
    double *            rcondv,
    lapack_complex_double *            work,
    lapack_int            lwork,
    double *            rwork,
    lapack_int *            iwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_zggevx_work==NULL) {
        _g_LAPACKE_zggevx_work = rindow_load_libopenblas_func("LAPACKE_zggevx_work"); 
        if(_g_LAPACKE_zggevx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zggevx_work(
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

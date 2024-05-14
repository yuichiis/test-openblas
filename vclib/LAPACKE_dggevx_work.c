#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggevx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggevx_work)( /* LAPACKE_dggevx_work */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* alphar */,
    double *            /* alphai */,
    double *            /* beta */,
    double *            /* vl */,
    lapack_int            /* ldvl */,
    double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* lscale */,
    double *            /* rscale */,
    double *            /* abnrm */,
    double *            /* bbnrm */,
    double *            /* rconde */,
    double *            /* rcondv */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_dggevx_work _g_LAPACKE_dggevx_work = NULL;
lapack_int LAPACKE_dggevx_work(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            alphar,
    double *            alphai,
    double *            beta,
    double *            vl,
    lapack_int            ldvl,
    double *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            lscale,
    double *            rscale,
    double *            abnrm,
    double *            bbnrm,
    double *            rconde,
    double *            rcondv,
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_dggevx_work==NULL) {
        _g_LAPACKE_dggevx_work = rindow_load_libopenblas_func("LAPACKE_dggevx_work"); 
        if(_g_LAPACKE_dggevx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggevx_work(
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
        alphar,
        alphai,
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
        iwork,
        bwork    
    );
}

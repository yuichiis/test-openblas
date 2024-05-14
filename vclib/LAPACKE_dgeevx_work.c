#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeevx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeevx_work)( /* LAPACKE_dgeevx_work */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* wr */,
    double *            /* wi */,
    double *            /* vl */,
    lapack_int            /* ldvl */,
    double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* scale */,
    double *            /* abnrm */,
    double *            /* rconde */,
    double *            /* rcondv */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dgeevx_work _g_LAPACKE_dgeevx_work = NULL;
lapack_int LAPACKE_dgeevx_work(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            wr,
    double *            wi,
    double *            vl,
    lapack_int            ldvl,
    double *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            scale,
    double *            abnrm,
    double *            rconde,
    double *            rcondv,
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dgeevx_work==NULL) {
        _g_LAPACKE_dgeevx_work = rindow_load_libopenblas_func("LAPACKE_dgeevx_work"); 
        if(_g_LAPACKE_dgeevx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeevx_work(
        matrix_layout,
        balanc,
        jobvl,
        jobvr,
        sense,
        n,
        a,
        lda,
        wr,
        wi,
        vl,
        ldvl,
        vr,
        ldvr,
        ilo,
        ihi,
        scale,
        abnrm,
        rconde,
        rcondv,
        work,
        lwork,
        iwork    
    );
}

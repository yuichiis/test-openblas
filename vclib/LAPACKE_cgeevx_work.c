#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgeevx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgeevx_work)( /* LAPACKE_cgeevx_work */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* w */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* scale */,
    float *            /* abnrm */,
    float *            /* rconde */,
    float *            /* rcondv */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */
);
static PFNLAPACKE_cgeevx_work _g_LAPACKE_cgeevx_work = NULL;
lapack_int LAPACKE_cgeevx_work(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            w,
    lapack_complex_float *            vl,
    lapack_int            ldvl,
    lapack_complex_float *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            scale,
    float *            abnrm,
    float *            rconde,
    float *            rcondv,
    lapack_complex_float *            work,
    lapack_int            lwork,
    float *            rwork
)
{
    if(_g_LAPACKE_cgeevx_work==NULL) {
        _g_LAPACKE_cgeevx_work = rindow_load_libopenblas_func("LAPACKE_cgeevx_work"); 
        if(_g_LAPACKE_cgeevx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgeevx_work(
        matrix_layout,
        balanc,
        jobvl,
        jobvr,
        sense,
        n,
        a,
        lda,
        w,
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
        rwork    
    );
}

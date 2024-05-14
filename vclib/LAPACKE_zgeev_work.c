#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgeev_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgeev_work)( /* LAPACKE_zgeev_work */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* w */,
    lapack_complex_double *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    double *            /* rwork */
);
static PFNLAPACKE_zgeev_work _g_LAPACKE_zgeev_work = NULL;
lapack_int LAPACKE_zgeev_work(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            w,
    lapack_complex_double *            vl,
    lapack_int            ldvl,
    lapack_complex_double *            vr,
    lapack_int            ldvr,
    lapack_complex_double *            work,
    lapack_int            lwork,
    double *            rwork
)
{
    if(_g_LAPACKE_zgeev_work==NULL) {
        _g_LAPACKE_zgeev_work = rindow_load_libopenblas_func("LAPACKE_zgeev_work"); 
        if(_g_LAPACKE_zgeev_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgeev_work(
        matrix_layout,
        jobvl,
        jobvr,
        n,
        a,
        lda,
        w,
        vl,
        ldvl,
        vr,
        ldvr,
        work,
        lwork,
        rwork    
    );
}

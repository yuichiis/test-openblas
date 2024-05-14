#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgeesx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgeesx_work)( /* LAPACKE_zgeesx_work */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_Z_SELECT1            /* select */,
    char            /* sense */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    lapack_complex_double *            /* w */,
    lapack_complex_double *            /* vs */,
    lapack_int            /* ldvs */,
    double *            /* rconde */,
    double *            /* rcondv */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    double *            /* rwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_zgeesx_work _g_LAPACKE_zgeesx_work = NULL;
lapack_int LAPACKE_zgeesx_work(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_Z_SELECT1            select,
    char            sense,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    lapack_complex_double *            w,
    lapack_complex_double *            vs,
    lapack_int            ldvs,
    double *            rconde,
    double *            rcondv,
    lapack_complex_double *            work,
    lapack_int            lwork,
    double *            rwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_zgeesx_work==NULL) {
        _g_LAPACKE_zgeesx_work = rindow_load_libopenblas_func("LAPACKE_zgeesx_work"); 
        if(_g_LAPACKE_zgeesx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgeesx_work(
        matrix_layout,
        jobvs,
        sort,
        select,
        sense,
        n,
        a,
        lda,
        sdim,
        w,
        vs,
        ldvs,
        rconde,
        rcondv,
        work,
        lwork,
        rwork,
        bwork    
    );
}

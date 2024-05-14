#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgesvj_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgesvj_work)( /* LAPACKE_dgesvj_work */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* sva */,
    lapack_int            /* mv */,
    double *            /* v */,
    lapack_int            /* ldv */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dgesvj_work _g_LAPACKE_dgesvj_work = NULL;
lapack_int LAPACKE_dgesvj_work(
    int            matrix_layout,
    char            joba,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            sva,
    lapack_int            mv,
    double *            v,
    lapack_int            ldv,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dgesvj_work==NULL) {
        _g_LAPACKE_dgesvj_work = rindow_load_libopenblas_func("LAPACKE_dgesvj_work"); 
        if(_g_LAPACKE_dgesvj_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgesvj_work(
        matrix_layout,
        joba,
        jobu,
        jobv,
        m,
        n,
        a,
        lda,
        sva,
        mv,
        v,
        ldv,
        work,
        lwork    
    );
}

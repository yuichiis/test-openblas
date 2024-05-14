#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgesvdq_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgesvdq_work)( /* LAPACKE_zgesvdq_work */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobp */,
    char            /* jobr */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    lapack_complex_double *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    lapack_int *            /* numrank */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */,
    lapack_complex_double *            /* cwork */,
    lapack_int            /* lcwork */,
    double *            /* rwork */,
    lapack_int            /* lrwork */
);
static PFNLAPACKE_zgesvdq_work _g_LAPACKE_zgesvdq_work = NULL;
lapack_int LAPACKE_zgesvdq_work(
    int            matrix_layout,
    char            joba,
    char            jobp,
    char            jobr,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            s,
    lapack_complex_double *            u,
    lapack_int            ldu,
    lapack_complex_double *            v,
    lapack_int            ldv,
    lapack_int *            numrank,
    lapack_int *            iwork,
    lapack_int            liwork,
    lapack_complex_double *            cwork,
    lapack_int            lcwork,
    double *            rwork,
    lapack_int            lrwork
)
{
    if(_g_LAPACKE_zgesvdq_work==NULL) {
        _g_LAPACKE_zgesvdq_work = rindow_load_libopenblas_func("LAPACKE_zgesvdq_work"); 
        if(_g_LAPACKE_zgesvdq_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgesvdq_work(
        matrix_layout,
        joba,
        jobp,
        jobr,
        jobu,
        jobv,
        m,
        n,
        a,
        lda,
        s,
        u,
        ldu,
        v,
        ldv,
        numrank,
        iwork,
        liwork,
        cwork,
        lcwork,
        rwork,
        lrwork    
    );
}

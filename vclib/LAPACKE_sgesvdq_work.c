#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesvdq_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesvdq_work)( /* LAPACKE_sgesvdq_work */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobp */,
    char            /* jobr */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* v */,
    lapack_int            /* ldv */,
    lapack_int *            /* numrank */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */,
    float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_int            /* lrwork */
);
static PFNLAPACKE_sgesvdq_work _g_LAPACKE_sgesvdq_work = NULL;
lapack_int LAPACKE_sgesvdq_work(
    int            matrix_layout,
    char            joba,
    char            jobp,
    char            jobr,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            s,
    float *            u,
    lapack_int            ldu,
    float *            v,
    lapack_int            ldv,
    lapack_int *            numrank,
    lapack_int *            iwork,
    lapack_int            liwork,
    float *            work,
    lapack_int            lwork,
    float *            rwork,
    lapack_int            lrwork
)
{
    if(_g_LAPACKE_sgesvdq_work==NULL) {
        _g_LAPACKE_sgesvdq_work = rindow_load_libopenblas_func("LAPACKE_sgesvdq_work"); 
        if(_g_LAPACKE_sgesvdq_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesvdq_work(
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
        work,
        lwork,
        rwork,
        lrwork    
    );
}

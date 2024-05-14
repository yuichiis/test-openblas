#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgesvdq_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgesvdq_work)( /* LAPACKE_cgesvdq_work */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobp */,
    char            /* jobr */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    lapack_complex_float *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_float *            /* v */,
    lapack_int            /* ldv */,
    lapack_int *            /* numrank */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */,
    lapack_complex_float *            /* cwork */,
    lapack_int            /* lcwork */,
    float *            /* rwork */,
    lapack_int            /* lrwork */
);
static PFNLAPACKE_cgesvdq_work _g_LAPACKE_cgesvdq_work = NULL;
lapack_int LAPACKE_cgesvdq_work(
    int            matrix_layout,
    char            joba,
    char            jobp,
    char            jobr,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float *            s,
    lapack_complex_float *            u,
    lapack_int            ldu,
    lapack_complex_float *            v,
    lapack_int            ldv,
    lapack_int *            numrank,
    lapack_int *            iwork,
    lapack_int            liwork,
    lapack_complex_float *            cwork,
    lapack_int            lcwork,
    float *            rwork,
    lapack_int            lrwork
)
{
    if(_g_LAPACKE_cgesvdq_work==NULL) {
        _g_LAPACKE_cgesvdq_work = rindow_load_libopenblas_func("LAPACKE_cgesvdq_work"); 
        if(_g_LAPACKE_cgesvdq_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgesvdq_work(
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

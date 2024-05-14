#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggsvd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggsvd_work)( /* LAPACKE_sggsvd_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* p */,
    lapack_int *            /* k */,
    lapack_int *            /* l */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* alpha */,
    float *            /* beta */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* v */,
    lapack_int            /* ldv */,
    float *            /* q */,
    lapack_int            /* ldq */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sggsvd_work _g_LAPACKE_sggsvd_work = NULL;
lapack_int LAPACKE_sggsvd_work(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            n,
    lapack_int            p,
    lapack_int *            k,
    lapack_int *            l,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            alpha,
    float *            beta,
    float *            u,
    lapack_int            ldu,
    float *            v,
    lapack_int            ldv,
    float *            q,
    lapack_int            ldq,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_sggsvd_work==NULL) {
        _g_LAPACKE_sggsvd_work = rindow_load_libopenblas_func("LAPACKE_sggsvd_work"); 
        if(_g_LAPACKE_sggsvd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggsvd_work(
        matrix_layout,
        jobu,
        jobv,
        jobq,
        m,
        n,
        p,
        k,
        l,
        a,
        lda,
        b,
        ldb,
        alpha,
        beta,
        u,
        ldu,
        v,
        ldv,
        q,
        ldq,
        work,
        iwork    
    );
}

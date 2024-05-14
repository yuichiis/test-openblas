#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgejsv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgejsv_work)( /* LAPACKE_sgejsv_work */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobr */,
    char            /* jobt */,
    char            /* jobp */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* sva */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* v */,
    lapack_int            /* ldv */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sgejsv_work _g_LAPACKE_sgejsv_work = NULL;
lapack_int LAPACKE_sgejsv_work(
    int            matrix_layout,
    char            joba,
    char            jobu,
    char            jobv,
    char            jobr,
    char            jobt,
    char            jobp,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            sva,
    float *            u,
    lapack_int            ldu,
    float *            v,
    lapack_int            ldv,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_sgejsv_work==NULL) {
        _g_LAPACKE_sgejsv_work = rindow_load_libopenblas_func("LAPACKE_sgejsv_work"); 
        if(_g_LAPACKE_sgejsv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgejsv_work(
        matrix_layout,
        joba,
        jobu,
        jobv,
        jobr,
        jobt,
        jobp,
        m,
        n,
        a,
        lda,
        sva,
        u,
        ldu,
        v,
        ldv,
        work,
        lwork,
        iwork    
    );
}

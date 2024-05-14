#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesvd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesvd_work)( /* LAPACKE_sgesvd_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobvt */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* vt */,
    lapack_int            /* ldvt */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sgesvd_work _g_LAPACKE_sgesvd_work = NULL;
lapack_int LAPACKE_sgesvd_work(
    int            matrix_layout,
    char            jobu,
    char            jobvt,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            s,
    float *            u,
    lapack_int            ldu,
    float *            vt,
    lapack_int            ldvt,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sgesvd_work==NULL) {
        _g_LAPACKE_sgesvd_work = rindow_load_libopenblas_func("LAPACKE_sgesvd_work"); 
        if(_g_LAPACKE_sgesvd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesvd_work(
        matrix_layout,
        jobu,
        jobvt,
        m,
        n,
        a,
        lda,
        s,
        u,
        ldu,
        vt,
        ldvt,
        work,
        lwork    
    );
}

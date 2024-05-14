#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgesvd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgesvd_work)( /* LAPACKE_dgesvd_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobvt */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* vt */,
    lapack_int            /* ldvt */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dgesvd_work _g_LAPACKE_dgesvd_work = NULL;
lapack_int LAPACKE_dgesvd_work(
    int            matrix_layout,
    char            jobu,
    char            jobvt,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            s,
    double *            u,
    lapack_int            ldu,
    double *            vt,
    lapack_int            ldvt,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dgesvd_work==NULL) {
        _g_LAPACKE_dgesvd_work = rindow_load_libopenblas_func("LAPACKE_dgesvd_work"); 
        if(_g_LAPACKE_dgesvd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgesvd_work(
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

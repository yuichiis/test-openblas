#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggsvd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggsvd)( /* LAPACKE_dggsvd */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* p */,
    lapack_int *            /* k */,
    lapack_int *            /* l */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* alpha */,
    double *            /* beta */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* v */,
    lapack_int            /* ldv */,
    double *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dggsvd _g_LAPACKE_dggsvd = NULL;
lapack_int LAPACKE_dggsvd(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            n,
    lapack_int            p,
    lapack_int *            k,
    lapack_int *            l,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            alpha,
    double *            beta,
    double *            u,
    lapack_int            ldu,
    double *            v,
    lapack_int            ldv,
    double *            q,
    lapack_int            ldq,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dggsvd==NULL) {
        _g_LAPACKE_dggsvd = rindow_load_libopenblas_func("LAPACKE_dggsvd"); 
        if(_g_LAPACKE_dggsvd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggsvd(
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
        iwork    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggsvd3 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggsvd3)( /* LAPACKE_dggsvd3 */
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
static PFNLAPACKE_dggsvd3 _g_LAPACKE_dggsvd3 = NULL;
lapack_int LAPACKE_dggsvd3(
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
    if(_g_LAPACKE_dggsvd3==NULL) {
        _g_LAPACKE_dggsvd3 = rindow_load_libopenblas_func("LAPACKE_dggsvd3"); 
        if(_g_LAPACKE_dggsvd3==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggsvd3(
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

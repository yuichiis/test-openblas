#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztgsen_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztgsen_work)( /* LAPACKE_ztgsen_work */
    int            /* matrix_layout */,
    lapack_int            /* ijob */,
    lapack_logical            /* wantq */,
    lapack_logical            /* wantz */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* alpha */,
    lapack_complex_double *            /* beta */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* m */,
    double *            /* pl */,
    double *            /* pr */,
    double *            /* dif */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_ztgsen_work _g_LAPACKE_ztgsen_work = NULL;
lapack_int LAPACKE_ztgsen_work(
    int            matrix_layout,
    lapack_int            ijob,
    lapack_logical            wantq,
    lapack_logical            wantz,
    const lapack_logical *            select,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            alpha,
    lapack_complex_double *            beta,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_complex_double *            z,
    lapack_int            ldz,
    lapack_int *            m,
    double *            pl,
    double *            pr,
    double *            dif,
    lapack_complex_double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_ztgsen_work==NULL) {
        _g_LAPACKE_ztgsen_work = rindow_load_libopenblas_func("LAPACKE_ztgsen_work"); 
        if(_g_LAPACKE_ztgsen_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztgsen_work(
        matrix_layout,
        ijob,
        wantq,
        wantz,
        select,
        n,
        a,
        lda,
        b,
        ldb,
        alpha,
        beta,
        q,
        ldq,
        z,
        ldz,
        m,
        pl,
        pr,
        dif,
        work,
        lwork,
        iwork,
        liwork    
    );
}

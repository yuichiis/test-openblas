#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctgsen_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctgsen_work)( /* LAPACKE_ctgsen_work */
    int            /* matrix_layout */,
    lapack_int            /* ijob */,
    lapack_logical            /* wantq */,
    lapack_logical            /* wantz */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* alpha */,
    lapack_complex_float *            /* beta */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* m */,
    float *            /* pl */,
    float *            /* pr */,
    float *            /* dif */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_ctgsen_work _g_LAPACKE_ctgsen_work = NULL;
lapack_int LAPACKE_ctgsen_work(
    int            matrix_layout,
    lapack_int            ijob,
    lapack_logical            wantq,
    lapack_logical            wantz,
    const lapack_logical *            select,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            alpha,
    lapack_complex_float *            beta,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_int *            m,
    float *            pl,
    float *            pr,
    float *            dif,
    lapack_complex_float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_ctgsen_work==NULL) {
        _g_LAPACKE_ctgsen_work = rindow_load_libopenblas_func("LAPACKE_ctgsen_work"); 
        if(_g_LAPACKE_ctgsen_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctgsen_work(
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

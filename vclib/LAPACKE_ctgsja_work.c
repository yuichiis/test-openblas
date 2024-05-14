#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctgsja_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctgsja_work)( /* LAPACKE_ctgsja_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    float            /* tola */,
    float            /* tolb */,
    float *            /* alpha */,
    float *            /* beta */,
    lapack_complex_float *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_float *            /* v */,
    lapack_int            /* ldv */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_float *            /* work */,
    lapack_int *            /* ncycle */
);
static PFNLAPACKE_ctgsja_work _g_LAPACKE_ctgsja_work = NULL;
lapack_int LAPACKE_ctgsja_work(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    float            tola,
    float            tolb,
    float *            alpha,
    float *            beta,
    lapack_complex_float *            u,
    lapack_int            ldu,
    lapack_complex_float *            v,
    lapack_int            ldv,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_complex_float *            work,
    lapack_int *            ncycle
)
{
    if(_g_LAPACKE_ctgsja_work==NULL) {
        _g_LAPACKE_ctgsja_work = rindow_load_libopenblas_func("LAPACKE_ctgsja_work"); 
        if(_g_LAPACKE_ctgsja_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctgsja_work(
        matrix_layout,
        jobu,
        jobv,
        jobq,
        m,
        p,
        n,
        k,
        l,
        a,
        lda,
        b,
        ldb,
        tola,
        tolb,
        alpha,
        beta,
        u,
        ldu,
        v,
        ldv,
        q,
        ldq,
        work,
        ncycle    
    );
}

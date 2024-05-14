#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggsvp_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggsvp_work)( /* LAPACKE_cggsvp_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    float            /* tola */,
    float            /* tolb */,
    lapack_int *            /* k */,
    lapack_int *            /* l */,
    lapack_complex_float *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_float *            /* v */,
    lapack_int            /* ldv */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* iwork */,
    float *            /* rwork */,
    lapack_complex_float *            /* tau */,
    lapack_complex_float *            /* work */
);
static PFNLAPACKE_cggsvp_work _g_LAPACKE_cggsvp_work = NULL;
lapack_int LAPACKE_cggsvp_work(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    float            tola,
    float            tolb,
    lapack_int *            k,
    lapack_int *            l,
    lapack_complex_float *            u,
    lapack_int            ldu,
    lapack_complex_float *            v,
    lapack_int            ldv,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_int *            iwork,
    float *            rwork,
    lapack_complex_float *            tau,
    lapack_complex_float *            work
)
{
    if(_g_LAPACKE_cggsvp_work==NULL) {
        _g_LAPACKE_cggsvp_work = rindow_load_libopenblas_func("LAPACKE_cggsvp_work"); 
        if(_g_LAPACKE_cggsvp_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggsvp_work(
        matrix_layout,
        jobu,
        jobv,
        jobq,
        m,
        p,
        n,
        a,
        lda,
        b,
        ldb,
        tola,
        tolb,
        k,
        l,
        u,
        ldu,
        v,
        ldv,
        q,
        ldq,
        iwork,
        rwork,
        tau,
        work    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zggsvp_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zggsvp_work)( /* LAPACKE_zggsvp_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    double            /* tola */,
    double            /* tolb */,
    lapack_int *            /* k */,
    lapack_int *            /* l */,
    lapack_complex_double *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* iwork */,
    double *            /* rwork */,
    lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zggsvp_work _g_LAPACKE_zggsvp_work = NULL;
lapack_int LAPACKE_zggsvp_work(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    double            tola,
    double            tolb,
    lapack_int *            k,
    lapack_int *            l,
    lapack_complex_double *            u,
    lapack_int            ldu,
    lapack_complex_double *            v,
    lapack_int            ldv,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_int *            iwork,
    double *            rwork,
    lapack_complex_double *            tau,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zggsvp_work==NULL) {
        _g_LAPACKE_zggsvp_work = rindow_load_libopenblas_func("LAPACKE_zggsvp_work"); 
        if(_g_LAPACKE_zggsvp_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zggsvp_work(
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

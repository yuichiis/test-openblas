#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggsvp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggsvp)( /* LAPACKE_dggsvp */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double            /* tola */,
    double            /* tolb */,
    lapack_int *            /* k */,
    lapack_int *            /* l */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* v */,
    lapack_int            /* ldv */,
    double *            /* q */,
    lapack_int            /* ldq */
);
static PFNLAPACKE_dggsvp _g_LAPACKE_dggsvp = NULL;
lapack_int LAPACKE_dggsvp(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double            tola,
    double            tolb,
    lapack_int *            k,
    lapack_int *            l,
    double *            u,
    lapack_int            ldu,
    double *            v,
    lapack_int            ldv,
    double *            q,
    lapack_int            ldq
)
{
    if(_g_LAPACKE_dggsvp==NULL) {
        _g_LAPACKE_dggsvp = rindow_load_libopenblas_func("LAPACKE_dggsvp"); 
        if(_g_LAPACKE_dggsvp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggsvp(
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
        ldq    
    );
}

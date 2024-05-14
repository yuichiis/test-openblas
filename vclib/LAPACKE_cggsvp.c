#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggsvp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggsvp)( /* LAPACKE_cggsvp */
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
    lapack_int            /* ldq */
);
static PFNLAPACKE_cggsvp _g_LAPACKE_cggsvp = NULL;
lapack_int LAPACKE_cggsvp(
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
    lapack_int            ldq
)
{
    if(_g_LAPACKE_cggsvp==NULL) {
        _g_LAPACKE_cggsvp = rindow_load_libopenblas_func("LAPACKE_cggsvp"); 
        if(_g_LAPACKE_cggsvp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggsvp(
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

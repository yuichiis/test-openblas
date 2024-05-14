#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtgsja not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtgsja)( /* LAPACKE_dtgsja */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double            /* tola */,
    double            /* tolb */,
    double *            /* alpha */,
    double *            /* beta */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* v */,
    lapack_int            /* ldv */,
    double *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* ncycle */
);
static PFNLAPACKE_dtgsja _g_LAPACKE_dtgsja = NULL;
lapack_int LAPACKE_dtgsja(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double            tola,
    double            tolb,
    double *            alpha,
    double *            beta,
    double *            u,
    lapack_int            ldu,
    double *            v,
    lapack_int            ldv,
    double *            q,
    lapack_int            ldq,
    lapack_int *            ncycle
)
{
    if(_g_LAPACKE_dtgsja==NULL) {
        _g_LAPACKE_dtgsja = rindow_load_libopenblas_func("LAPACKE_dtgsja"); 
        if(_g_LAPACKE_dtgsja==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtgsja(
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
        ncycle    
    );
}

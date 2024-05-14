#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztgsja not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztgsja)( /* LAPACKE_ztgsja */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobq */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    double            /* tola */,
    double            /* tolb */,
    double *            /* alpha */,
    double *            /* beta */,
    lapack_complex_double *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* ncycle */
);
static PFNLAPACKE_ztgsja _g_LAPACKE_ztgsja = NULL;
lapack_int LAPACKE_ztgsja(
    int            matrix_layout,
    char            jobu,
    char            jobv,
    char            jobq,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    double            tola,
    double            tolb,
    double *            alpha,
    double *            beta,
    lapack_complex_double *            u,
    lapack_int            ldu,
    lapack_complex_double *            v,
    lapack_int            ldv,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_int *            ncycle
)
{
    if(_g_LAPACKE_ztgsja==NULL) {
        _g_LAPACKE_ztgsja = rindow_load_libopenblas_func("LAPACKE_ztgsja"); 
        if(_g_LAPACKE_ztgsja==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztgsja(
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

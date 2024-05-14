#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtgsen not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtgsen)( /* LAPACKE_dtgsen */
    int            /* matrix_layout */,
    lapack_int            /* ijob */,
    lapack_logical            /* wantq */,
    lapack_logical            /* wantz */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* alphar */,
    double *            /* alphai */,
    double *            /* beta */,
    double *            /* q */,
    lapack_int            /* ldq */,
    double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* m */,
    double *            /* pl */,
    double *            /* pr */,
    double *            /* dif */
);
static PFNLAPACKE_dtgsen _g_LAPACKE_dtgsen = NULL;
lapack_int LAPACKE_dtgsen(
    int            matrix_layout,
    lapack_int            ijob,
    lapack_logical            wantq,
    lapack_logical            wantz,
    const lapack_logical *            select,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            alphar,
    double *            alphai,
    double *            beta,
    double *            q,
    lapack_int            ldq,
    double *            z,
    lapack_int            ldz,
    lapack_int *            m,
    double *            pl,
    double *            pr,
    double *            dif
)
{
    if(_g_LAPACKE_dtgsen==NULL) {
        _g_LAPACKE_dtgsen = rindow_load_libopenblas_func("LAPACKE_dtgsen"); 
        if(_g_LAPACKE_dtgsen==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtgsen(
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
        alphar,
        alphai,
        beta,
        q,
        ldq,
        z,
        ldz,
        m,
        pl,
        pr,
        dif    
    );
}

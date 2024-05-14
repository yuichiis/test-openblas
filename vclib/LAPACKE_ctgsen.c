#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctgsen not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctgsen)( /* LAPACKE_ctgsen */
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
    float *            /* dif */
);
static PFNLAPACKE_ctgsen _g_LAPACKE_ctgsen = NULL;
lapack_int LAPACKE_ctgsen(
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
    float *            dif
)
{
    if(_g_LAPACKE_ctgsen==NULL) {
        _g_LAPACKE_ctgsen = rindow_load_libopenblas_func("LAPACKE_ctgsen"); 
        if(_g_LAPACKE_ctgsen==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctgsen(
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
        dif    
    );
}

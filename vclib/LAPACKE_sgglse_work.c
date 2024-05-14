#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgglse_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgglse_work)( /* LAPACKE_sgglse_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* p */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* c */,
    float *            /* d */,
    float *            /* x */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sgglse_work _g_LAPACKE_sgglse_work = NULL;
lapack_int LAPACKE_sgglse_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            p,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            c,
    float *            d,
    float *            x,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sgglse_work==NULL) {
        _g_LAPACKE_sgglse_work = rindow_load_libopenblas_func("LAPACKE_sgglse_work"); 
        if(_g_LAPACKE_sgglse_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgglse_work(
        matrix_layout,
        m,
        n,
        p,
        a,
        lda,
        b,
        ldb,
        c,
        d,
        x,
        work,
        lwork    
    );
}

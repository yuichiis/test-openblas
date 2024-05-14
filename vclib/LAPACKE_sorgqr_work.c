#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorgqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorgqr_work)( /* LAPACKE_sorgqr_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sorgqr_work _g_LAPACKE_sorgqr_work = NULL;
lapack_int LAPACKE_sorgqr_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    float *            a,
    lapack_int            lda,
    const float *            tau,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sorgqr_work==NULL) {
        _g_LAPACKE_sorgqr_work = rindow_load_libopenblas_func("LAPACKE_sorgqr_work"); 
        if(_g_LAPACKE_sorgqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorgqr_work(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau,
        work,
        lwork    
    );
}

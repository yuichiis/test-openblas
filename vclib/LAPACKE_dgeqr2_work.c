#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeqr2_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeqr2_work)( /* LAPACKE_dgeqr2_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* tau */,
    double *            /* work */
);
static PFNLAPACKE_dgeqr2_work _g_LAPACKE_dgeqr2_work = NULL;
lapack_int LAPACKE_dgeqr2_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            tau,
    double *            work
)
{
    if(_g_LAPACKE_dgeqr2_work==NULL) {
        _g_LAPACKE_dgeqr2_work = rindow_load_libopenblas_func("LAPACKE_dgeqr2_work"); 
        if(_g_LAPACKE_dgeqr2_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeqr2_work(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau,
        work    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorgtsqr_row_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorgtsqr_row_work)( /* LAPACKE_sorgtsqr_row_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb */,
    lapack_int            /* nb */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sorgtsqr_row_work _g_LAPACKE_sorgtsqr_row_work = NULL;
lapack_int LAPACKE_sorgtsqr_row_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb,
    lapack_int            nb,
    float *            a,
    lapack_int            lda,
    const float *            t,
    lapack_int            ldt,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sorgtsqr_row_work==NULL) {
        _g_LAPACKE_sorgtsqr_row_work = rindow_load_libopenblas_func("LAPACKE_sorgtsqr_row_work"); 
        if(_g_LAPACKE_sorgtsqr_row_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorgtsqr_row_work(
        matrix_layout,
        m,
        n,
        mb,
        nb,
        a,
        lda,
        t,
        ldt,
        work,
        lwork    
    );
}

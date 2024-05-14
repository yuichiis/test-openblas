#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctpqrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctpqrt_work)( /* LAPACKE_ctpqrt_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* l */,
    lapack_int            /* nb */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* work */
);
static PFNLAPACKE_ctpqrt_work _g_LAPACKE_ctpqrt_work = NULL;
lapack_int LAPACKE_ctpqrt_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            l,
    lapack_int            nb,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            work
)
{
    if(_g_LAPACKE_ctpqrt_work==NULL) {
        _g_LAPACKE_ctpqrt_work = rindow_load_libopenblas_func("LAPACKE_ctpqrt_work"); 
        if(_g_LAPACKE_ctpqrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctpqrt_work(
        matrix_layout,
        m,
        n,
        l,
        nb,
        a,
        lda,
        b,
        ldb,
        t,
        ldt,
        work    
    );
}

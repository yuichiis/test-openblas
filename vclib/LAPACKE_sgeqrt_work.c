#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeqrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeqrt_work)( /* LAPACKE_sgeqrt_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nb */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* work */
);
static PFNLAPACKE_sgeqrt_work _g_LAPACKE_sgeqrt_work = NULL;
lapack_int LAPACKE_sgeqrt_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nb,
    float *            a,
    lapack_int            lda,
    float *            t,
    lapack_int            ldt,
    float *            work
)
{
    if(_g_LAPACKE_sgeqrt_work==NULL) {
        _g_LAPACKE_sgeqrt_work = rindow_load_libopenblas_func("LAPACKE_sgeqrt_work"); 
        if(_g_LAPACKE_sgeqrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeqrt_work(
        matrix_layout,
        m,
        n,
        nb,
        a,
        lda,
        t,
        ldt,
        work    
    );
}

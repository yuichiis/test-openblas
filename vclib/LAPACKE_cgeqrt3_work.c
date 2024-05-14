#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgeqrt3_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgeqrt3_work)( /* LAPACKE_cgeqrt3_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_cgeqrt3_work _g_LAPACKE_cgeqrt3_work = NULL;
lapack_int LAPACKE_cgeqrt3_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_cgeqrt3_work==NULL) {
        _g_LAPACKE_cgeqrt3_work = rindow_load_libopenblas_func("LAPACKE_cgeqrt3_work"); 
        if(_g_LAPACKE_cgeqrt3_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgeqrt3_work(
        matrix_layout,
        m,
        n,
        a,
        lda,
        t,
        ldt    
    );
}

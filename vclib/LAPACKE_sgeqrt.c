#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeqrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeqrt)( /* LAPACKE_sgeqrt */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nb */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_sgeqrt _g_LAPACKE_sgeqrt = NULL;
lapack_int LAPACKE_sgeqrt(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nb,
    float *            a,
    lapack_int            lda,
    float *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_sgeqrt==NULL) {
        _g_LAPACKE_sgeqrt = rindow_load_libopenblas_func("LAPACKE_sgeqrt"); 
        if(_g_LAPACKE_sgeqrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeqrt(
        matrix_layout,
        m,
        n,
        nb,
        a,
        lda,
        t,
        ldt    
    );
}

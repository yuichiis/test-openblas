#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorgtsqr_row not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorgtsqr_row)( /* LAPACKE_sorgtsqr_row */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb */,
    lapack_int            /* nb */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_sorgtsqr_row _g_LAPACKE_sorgtsqr_row = NULL;
lapack_int LAPACKE_sorgtsqr_row(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb,
    lapack_int            nb,
    float *            a,
    lapack_int            lda,
    const float *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_sorgtsqr_row==NULL) {
        _g_LAPACKE_sorgtsqr_row = rindow_load_libopenblas_func("LAPACKE_sorgtsqr_row"); 
        if(_g_LAPACKE_sorgtsqr_row==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorgtsqr_row(
        matrix_layout,
        m,
        n,
        mb,
        nb,
        a,
        lda,
        t,
        ldt    
    );
}

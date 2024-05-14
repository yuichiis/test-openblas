#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dorgtsqr_row not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dorgtsqr_row)( /* LAPACKE_dorgtsqr_row */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb */,
    lapack_int            /* nb */,
    double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_dorgtsqr_row _g_LAPACKE_dorgtsqr_row = NULL;
lapack_int LAPACKE_dorgtsqr_row(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb,
    lapack_int            nb,
    double *            a,
    lapack_int            lda,
    const double *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_dorgtsqr_row==NULL) {
        _g_LAPACKE_dorgtsqr_row = rindow_load_libopenblas_func("LAPACKE_dorgtsqr_row"); 
        if(_g_LAPACKE_dorgtsqr_row==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dorgtsqr_row(
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

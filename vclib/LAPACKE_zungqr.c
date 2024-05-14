#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zungqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zungqr)( /* LAPACKE_zungqr */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zungqr _g_LAPACKE_zungqr = NULL;
lapack_int LAPACKE_zungqr(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zungqr==NULL) {
        _g_LAPACKE_zungqr = rindow_load_libopenblas_func("LAPACKE_zungqr"); 
        if(_g_LAPACKE_zungqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zungqr(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}

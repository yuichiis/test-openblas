#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cungqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cungqr)( /* LAPACKE_cungqr */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* tau */
);
static PFNLAPACKE_cungqr _g_LAPACKE_cungqr = NULL;
lapack_int LAPACKE_cungqr(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_cungqr==NULL) {
        _g_LAPACKE_cungqr = rindow_load_libopenblas_func("LAPACKE_cungqr"); 
        if(_g_LAPACKE_cungqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cungqr(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgeqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgeqr)( /* LAPACKE_zgeqr */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* t */,
    lapack_int            /* tsize */
);
static PFNLAPACKE_zgeqr _g_LAPACKE_zgeqr = NULL;
lapack_int LAPACKE_zgeqr(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            t,
    lapack_int            tsize
)
{
    if(_g_LAPACKE_zgeqr==NULL) {
        _g_LAPACKE_zgeqr = rindow_load_libopenblas_func("LAPACKE_zgeqr"); 
        if(_g_LAPACKE_zgeqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgeqr(
        matrix_layout,
        m,
        n,
        a,
        lda,
        t,
        tsize    
    );
}

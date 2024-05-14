#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgeqrfp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgeqrfp)( /* LAPACKE_zgeqrfp */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zgeqrfp _g_LAPACKE_zgeqrfp = NULL;
lapack_int LAPACKE_zgeqrfp(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zgeqrfp==NULL) {
        _g_LAPACKE_zgeqrfp = rindow_load_libopenblas_func("LAPACKE_zgeqrfp"); 
        if(_g_LAPACKE_zgeqrfp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgeqrfp(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

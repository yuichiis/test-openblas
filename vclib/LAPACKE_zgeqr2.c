#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgeqr2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgeqr2)( /* LAPACKE_zgeqr2 */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zgeqr2 _g_LAPACKE_zgeqr2 = NULL;
lapack_int LAPACKE_zgeqr2(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zgeqr2==NULL) {
        _g_LAPACKE_zgeqr2 = rindow_load_libopenblas_func("LAPACKE_zgeqr2"); 
        if(_g_LAPACKE_zgeqr2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgeqr2(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

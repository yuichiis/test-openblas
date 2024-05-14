#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeqrfp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeqrfp)( /* LAPACKE_dgeqrfp */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* tau */
);
static PFNLAPACKE_dgeqrfp _g_LAPACKE_dgeqrfp = NULL;
lapack_int LAPACKE_dgeqrfp(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            tau
)
{
    if(_g_LAPACKE_dgeqrfp==NULL) {
        _g_LAPACKE_dgeqrfp = rindow_load_libopenblas_func("LAPACKE_dgeqrfp"); 
        if(_g_LAPACKE_dgeqrfp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeqrfp(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

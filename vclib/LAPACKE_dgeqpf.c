#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeqpf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeqpf)( /* LAPACKE_dgeqpf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* jpvt */,
    double *            /* tau */
);
static PFNLAPACKE_dgeqpf _g_LAPACKE_dgeqpf = NULL;
lapack_int LAPACKE_dgeqpf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            jpvt,
    double *            tau
)
{
    if(_g_LAPACKE_dgeqpf==NULL) {
        _g_LAPACKE_dgeqpf = rindow_load_libopenblas_func("LAPACKE_dgeqpf"); 
        if(_g_LAPACKE_dgeqpf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeqpf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        jpvt,
        tau    
    );
}

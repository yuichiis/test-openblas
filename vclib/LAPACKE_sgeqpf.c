#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeqpf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeqpf)( /* LAPACKE_sgeqpf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* jpvt */,
    float *            /* tau */
);
static PFNLAPACKE_sgeqpf _g_LAPACKE_sgeqpf = NULL;
lapack_int LAPACKE_sgeqpf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            jpvt,
    float *            tau
)
{
    if(_g_LAPACKE_sgeqpf==NULL) {
        _g_LAPACKE_sgeqpf = rindow_load_libopenblas_func("LAPACKE_sgeqpf"); 
        if(_g_LAPACKE_sgeqpf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeqpf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        jpvt,
        tau    
    );
}

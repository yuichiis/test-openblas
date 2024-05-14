#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorgrq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorgrq)( /* LAPACKE_sorgrq */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */
);
static PFNLAPACKE_sorgrq _g_LAPACKE_sorgrq = NULL;
lapack_int LAPACKE_sorgrq(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    float *            a,
    lapack_int            lda,
    const float *            tau
)
{
    if(_g_LAPACKE_sorgrq==NULL) {
        _g_LAPACKE_sorgrq = rindow_load_libopenblas_func("LAPACKE_sorgrq"); 
        if(_g_LAPACKE_sorgrq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorgrq(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}

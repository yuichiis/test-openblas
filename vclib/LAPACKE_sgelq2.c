#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgelq2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgelq2)( /* LAPACKE_sgelq2 */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* tau */
);
static PFNLAPACKE_sgelq2 _g_LAPACKE_sgelq2 = NULL;
lapack_int LAPACKE_sgelq2(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            tau
)
{
    if(_g_LAPACKE_sgelq2==NULL) {
        _g_LAPACKE_sgelq2 = rindow_load_libopenblas_func("LAPACKE_sgelq2"); 
        if(_g_LAPACKE_sgelq2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgelq2(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

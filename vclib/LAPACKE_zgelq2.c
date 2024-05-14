#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgelq2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgelq2)( /* LAPACKE_zgelq2 */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zgelq2 _g_LAPACKE_zgelq2 = NULL;
lapack_int LAPACKE_zgelq2(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zgelq2==NULL) {
        _g_LAPACKE_zgelq2 = rindow_load_libopenblas_func("LAPACKE_zgelq2"); 
        if(_g_LAPACKE_zgelq2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgelq2(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgelqf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgelqf)( /* LAPACKE_zgelqf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zgelqf _g_LAPACKE_zgelqf = NULL;
lapack_int LAPACKE_zgelqf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zgelqf==NULL) {
        _g_LAPACKE_zgelqf = rindow_load_libopenblas_func("LAPACKE_zgelqf"); 
        if(_g_LAPACKE_zgelqf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgelqf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

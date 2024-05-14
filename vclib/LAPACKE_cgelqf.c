#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgelqf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgelqf)( /* LAPACKE_cgelqf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* tau */
);
static PFNLAPACKE_cgelqf _g_LAPACKE_cgelqf = NULL;
lapack_int LAPACKE_cgelqf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_cgelqf==NULL) {
        _g_LAPACKE_cgelqf = rindow_load_libopenblas_func("LAPACKE_cgelqf"); 
        if(_g_LAPACKE_cgelqf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgelqf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

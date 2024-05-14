#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctzrzf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctzrzf)( /* LAPACKE_ctzrzf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* tau */
);
static PFNLAPACKE_ctzrzf _g_LAPACKE_ctzrzf = NULL;
lapack_int LAPACKE_ctzrzf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_ctzrzf==NULL) {
        _g_LAPACKE_ctzrzf = rindow_load_libopenblas_func("LAPACKE_ctzrzf"); 
        if(_g_LAPACKE_ctzrzf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctzrzf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stzrzf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stzrzf)( /* LAPACKE_stzrzf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* tau */
);
static PFNLAPACKE_stzrzf _g_LAPACKE_stzrzf = NULL;
lapack_int LAPACKE_stzrzf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            tau
)
{
    if(_g_LAPACKE_stzrzf==NULL) {
        _g_LAPACKE_stzrzf = rindow_load_libopenblas_func("LAPACKE_stzrzf"); 
        if(_g_LAPACKE_stzrzf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stzrzf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

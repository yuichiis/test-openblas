#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtzrzf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtzrzf)( /* LAPACKE_dtzrzf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* tau */
);
static PFNLAPACKE_dtzrzf _g_LAPACKE_dtzrzf = NULL;
lapack_int LAPACKE_dtzrzf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            tau
)
{
    if(_g_LAPACKE_dtzrzf==NULL) {
        _g_LAPACKE_dtzrzf = rindow_load_libopenblas_func("LAPACKE_dtzrzf"); 
        if(_g_LAPACKE_dtzrzf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtzrzf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

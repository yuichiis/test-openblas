#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlag2s not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlag2s)( /* LAPACKE_dlag2s */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    float *            /* sa */,
    lapack_int            /* ldsa */
);
static PFNLAPACKE_dlag2s _g_LAPACKE_dlag2s = NULL;
lapack_int LAPACKE_dlag2s(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    float *            sa,
    lapack_int            ldsa
)
{
    if(_g_LAPACKE_dlag2s==NULL) {
        _g_LAPACKE_dlag2s = rindow_load_libopenblas_func("LAPACKE_dlag2s"); 
        if(_g_LAPACKE_dlag2s==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlag2s(
        matrix_layout,
        m,
        n,
        a,
        lda,
        sa,
        ldsa    
    );
}

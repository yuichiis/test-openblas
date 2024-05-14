#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeqlf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeqlf)( /* LAPACKE_dgeqlf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* tau */
);
static PFNLAPACKE_dgeqlf _g_LAPACKE_dgeqlf = NULL;
lapack_int LAPACKE_dgeqlf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            tau
)
{
    if(_g_LAPACKE_dgeqlf==NULL) {
        _g_LAPACKE_dgeqlf = rindow_load_libopenblas_func("LAPACKE_dgeqlf"); 
        if(_g_LAPACKE_dgeqlf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeqlf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

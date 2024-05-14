#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgeqlf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgeqlf)( /* LAPACKE_zgeqlf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zgeqlf _g_LAPACKE_zgeqlf = NULL;
lapack_int LAPACKE_zgeqlf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zgeqlf==NULL) {
        _g_LAPACKE_zgeqlf = rindow_load_libopenblas_func("LAPACKE_zgeqlf"); 
        if(_g_LAPACKE_zgeqlf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgeqlf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}

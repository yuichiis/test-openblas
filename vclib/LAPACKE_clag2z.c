#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clag2z not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clag2z)( /* LAPACKE_clag2z */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* sa */,
    lapack_int            /* ldsa */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_clag2z _g_LAPACKE_clag2z = NULL;
lapack_int LAPACKE_clag2z(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            sa,
    lapack_int            ldsa,
    lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_clag2z==NULL) {
        _g_LAPACKE_clag2z = rindow_load_libopenblas_func("LAPACKE_clag2z"); 
        if(_g_LAPACKE_clag2z==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clag2z(
        matrix_layout,
        m,
        n,
        sa,
        ldsa,
        a,
        lda    
    );
}

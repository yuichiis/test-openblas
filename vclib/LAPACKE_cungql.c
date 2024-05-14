#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cungql not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cungql)( /* LAPACKE_cungql */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* tau */
);
static PFNLAPACKE_cungql _g_LAPACKE_cungql = NULL;
lapack_int LAPACKE_cungql(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_cungql==NULL) {
        _g_LAPACKE_cungql = rindow_load_libopenblas_func("LAPACKE_cungql"); 
        if(_g_LAPACKE_cungql==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cungql(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}

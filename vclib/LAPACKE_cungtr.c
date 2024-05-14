#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cungtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cungtr)( /* LAPACKE_cungtr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* tau */
);
static PFNLAPACKE_cungtr _g_LAPACKE_cungtr = NULL;
lapack_int LAPACKE_cungtr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_cungtr==NULL) {
        _g_LAPACKE_cungtr = rindow_load_libopenblas_func("LAPACKE_cungtr"); 
        if(_g_LAPACKE_cungtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cungtr(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        tau    
    );
}

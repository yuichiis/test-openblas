#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zungtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zungtr)( /* LAPACKE_zungtr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zungtr _g_LAPACKE_zungtr = NULL;
lapack_int LAPACKE_zungtr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zungtr==NULL) {
        _g_LAPACKE_zungtr = rindow_load_libopenblas_func("LAPACKE_zungtr"); 
        if(_g_LAPACKE_zungtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zungtr(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        tau    
    );
}

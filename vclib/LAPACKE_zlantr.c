#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlantr not found\n";
typedef double (CALLBACK* PFNLAPACKE_zlantr)( /* LAPACKE_zlantr */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_zlantr _g_LAPACKE_zlantr = NULL;
double LAPACKE_zlantr(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_zlantr==NULL) {
        _g_LAPACKE_zlantr = rindow_load_libopenblas_func("LAPACKE_zlantr"); 
        if(_g_LAPACKE_zlantr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlantr(
        matrix_layout,
        norm,
        uplo,
        diag,
        m,
        n,
        a,
        lda    
    );
}

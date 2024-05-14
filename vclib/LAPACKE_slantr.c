#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slantr not found\n";
typedef float (CALLBACK* PFNLAPACKE_slantr)( /* LAPACKE_slantr */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_slantr _g_LAPACKE_slantr = NULL;
float LAPACKE_slantr(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_slantr==NULL) {
        _g_LAPACKE_slantr = rindow_load_libopenblas_func("LAPACKE_slantr"); 
        if(_g_LAPACKE_slantr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slantr(
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

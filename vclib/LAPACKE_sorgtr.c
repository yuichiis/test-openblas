#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorgtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorgtr)( /* LAPACKE_sorgtr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */
);
static PFNLAPACKE_sorgtr _g_LAPACKE_sorgtr = NULL;
lapack_int LAPACKE_sorgtr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    const float *            tau
)
{
    if(_g_LAPACKE_sorgtr==NULL) {
        _g_LAPACKE_sorgtr = rindow_load_libopenblas_func("LAPACKE_sorgtr"); 
        if(_g_LAPACKE_sorgtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorgtr(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        tau    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctpttr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctpttr)( /* LAPACKE_ctpttr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_ctpttr _g_LAPACKE_ctpttr = NULL;
lapack_int LAPACKE_ctpttr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            ap,
    lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_ctpttr==NULL) {
        _g_LAPACKE_ctpttr = rindow_load_libopenblas_func("LAPACKE_ctpttr"); 
        if(_g_LAPACKE_ctpttr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctpttr(
        matrix_layout,
        uplo,
        n,
        ap,
        a,
        lda    
    );
}

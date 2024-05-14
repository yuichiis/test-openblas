#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtpttr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtpttr)( /* LAPACKE_dtpttr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* ap */,
    double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_dtpttr _g_LAPACKE_dtpttr = NULL;
lapack_int LAPACKE_dtpttr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            ap,
    double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_dtpttr==NULL) {
        _g_LAPACKE_dtpttr = rindow_load_libopenblas_func("LAPACKE_dtpttr"); 
        if(_g_LAPACKE_dtpttr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtpttr(
        matrix_layout,
        uplo,
        n,
        ap,
        a,
        lda    
    );
}

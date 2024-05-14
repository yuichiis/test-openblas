#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztfttr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztfttr)( /* LAPACKE_ztfttr */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* arf */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_ztfttr _g_LAPACKE_ztfttr = NULL;
lapack_int LAPACKE_ztfttr(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            arf,
    lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_ztfttr==NULL) {
        _g_LAPACKE_ztfttr = rindow_load_libopenblas_func("LAPACKE_ztfttr"); 
        if(_g_LAPACKE_ztfttr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztfttr(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        a,
        lda    
    );
}

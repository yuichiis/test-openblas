#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpstrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpstrf)( /* LAPACKE_zpstrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* piv */,
    lapack_int *            /* rank */,
    double            /* tol */
);
static PFNLAPACKE_zpstrf _g_LAPACKE_zpstrf = NULL;
lapack_int LAPACKE_zpstrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int *            piv,
    lapack_int *            rank,
    double            tol
)
{
    if(_g_LAPACKE_zpstrf==NULL) {
        _g_LAPACKE_zpstrf = rindow_load_libopenblas_func("LAPACKE_zpstrf"); 
        if(_g_LAPACKE_zpstrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpstrf(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        piv,
        rank,
        tol    
    );
}

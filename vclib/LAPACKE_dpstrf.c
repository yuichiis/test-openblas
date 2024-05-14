#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpstrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpstrf)( /* LAPACKE_dpstrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* piv */,
    lapack_int *            /* rank */,
    double            /* tol */
);
static PFNLAPACKE_dpstrf _g_LAPACKE_dpstrf = NULL;
lapack_int LAPACKE_dpstrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            piv,
    lapack_int *            rank,
    double            tol
)
{
    if(_g_LAPACKE_dpstrf==NULL) {
        _g_LAPACKE_dpstrf = rindow_load_libopenblas_func("LAPACKE_dpstrf"); 
        if(_g_LAPACKE_dpstrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpstrf(
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

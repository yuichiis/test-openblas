#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpstrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpstrf)( /* LAPACKE_cpstrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* piv */,
    lapack_int *            /* rank */,
    float            /* tol */
);
static PFNLAPACKE_cpstrf _g_LAPACKE_cpstrf = NULL;
lapack_int LAPACKE_cpstrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            piv,
    lapack_int *            rank,
    float            tol
)
{
    if(_g_LAPACKE_cpstrf==NULL) {
        _g_LAPACKE_cpstrf = rindow_load_libopenblas_func("LAPACKE_cpstrf"); 
        if(_g_LAPACKE_cpstrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpstrf(
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

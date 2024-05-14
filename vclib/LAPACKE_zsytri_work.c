#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsytri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsytri_work)( /* LAPACKE_zsytri_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zsytri_work _g_LAPACKE_zsytri_work = NULL;
lapack_int LAPACKE_zsytri_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zsytri_work==NULL) {
        _g_LAPACKE_zsytri_work = rindow_load_libopenblas_func("LAPACKE_zsytri_work"); 
        if(_g_LAPACKE_zsytri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsytri_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv,
        work    
    );
}

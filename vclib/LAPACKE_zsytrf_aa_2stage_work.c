#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsytrf_aa_2stage_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsytrf_aa_2stage_work)( /* LAPACKE_zsytrf_aa_2stage_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* tb */,
    lapack_int            /* ltb */,
    lapack_int *            /* ipiv */,
    lapack_int *            /* ipiv2 */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_zsytrf_aa_2stage_work _g_LAPACKE_zsytrf_aa_2stage_work = NULL;
lapack_int LAPACKE_zsytrf_aa_2stage_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            tb,
    lapack_int            ltb,
    lapack_int *            ipiv,
    lapack_int *            ipiv2,
    lapack_complex_double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_zsytrf_aa_2stage_work==NULL) {
        _g_LAPACKE_zsytrf_aa_2stage_work = rindow_load_libopenblas_func("LAPACKE_zsytrf_aa_2stage_work"); 
        if(_g_LAPACKE_zsytrf_aa_2stage_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsytrf_aa_2stage_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        tb,
        ltb,
        ipiv,
        ipiv2,
        work,
        lwork    
    );
}

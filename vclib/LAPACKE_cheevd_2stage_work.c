#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cheevd_2stage_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cheevd_2stage_work)( /* LAPACKE_cheevd_2stage_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* w */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_int            /* lrwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_cheevd_2stage_work _g_LAPACKE_cheevd_2stage_work = NULL;
lapack_int LAPACKE_cheevd_2stage_work(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float *            w,
    lapack_complex_float *            work,
    lapack_int            lwork,
    float *            rwork,
    lapack_int            lrwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_cheevd_2stage_work==NULL) {
        _g_LAPACKE_cheevd_2stage_work = rindow_load_libopenblas_func("LAPACKE_cheevd_2stage_work"); 
        if(_g_LAPACKE_cheevd_2stage_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cheevd_2stage_work(
        matrix_layout,
        jobz,
        uplo,
        n,
        a,
        lda,
        w,
        work,
        lwork,
        rwork,
        lrwork,
        iwork,
        liwork    
    );
}

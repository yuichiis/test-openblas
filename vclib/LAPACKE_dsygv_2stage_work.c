#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsygv_2stage_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsygv_2stage_work)( /* LAPACKE_dsygv_2stage_work */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* w */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dsygv_2stage_work _g_LAPACKE_dsygv_2stage_work = NULL;
lapack_int LAPACKE_dsygv_2stage_work(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            w,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dsygv_2stage_work==NULL) {
        _g_LAPACKE_dsygv_2stage_work = rindow_load_libopenblas_func("LAPACKE_dsygv_2stage_work"); 
        if(_g_LAPACKE_dsygv_2stage_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsygv_2stage_work(
        matrix_layout,
        itype,
        jobz,
        uplo,
        n,
        a,
        lda,
        b,
        ldb,
        w,
        work,
        lwork    
    );
}

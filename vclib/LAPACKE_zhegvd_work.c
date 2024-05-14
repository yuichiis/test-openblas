#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhegvd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhegvd_work)( /* LAPACKE_zhegvd_work */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* w */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    double *            /* rwork */,
    lapack_int            /* lrwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_zhegvd_work _g_LAPACKE_zhegvd_work = NULL;
lapack_int LAPACKE_zhegvd_work(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    double *            w,
    lapack_complex_double *            work,
    lapack_int            lwork,
    double *            rwork,
    lapack_int            lrwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_zhegvd_work==NULL) {
        _g_LAPACKE_zhegvd_work = rindow_load_libopenblas_func("LAPACKE_zhegvd_work"); 
        if(_g_LAPACKE_zhegvd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhegvd_work(
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
        lwork,
        rwork,
        lrwork,
        iwork,
        liwork    
    );
}

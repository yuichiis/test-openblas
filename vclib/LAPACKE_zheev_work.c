#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zheev_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zheev_work)( /* LAPACKE_zheev_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* w */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    double *            /* rwork */
);
static PFNLAPACKE_zheev_work _g_LAPACKE_zheev_work = NULL;
lapack_int LAPACKE_zheev_work(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            w,
    lapack_complex_double *            work,
    lapack_int            lwork,
    double *            rwork
)
{
    if(_g_LAPACKE_zheev_work==NULL) {
        _g_LAPACKE_zheev_work = rindow_load_libopenblas_func("LAPACKE_zheev_work"); 
        if(_g_LAPACKE_zheev_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zheev_work(
        matrix_layout,
        jobz,
        uplo,
        n,
        a,
        lda,
        w,
        work,
        lwork,
        rwork    
    );
}

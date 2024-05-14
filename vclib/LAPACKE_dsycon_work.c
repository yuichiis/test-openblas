#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsycon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsycon_work)( /* LAPACKE_dsycon_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dsycon_work _g_LAPACKE_dsycon_work = NULL;
lapack_int LAPACKE_dsycon_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dsycon_work==NULL) {
        _g_LAPACKE_dsycon_work = rindow_load_libopenblas_func("LAPACKE_dsycon_work"); 
        if(_g_LAPACKE_dsycon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsycon_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv,
        anorm,
        rcond,
        work,
        iwork    
    );
}

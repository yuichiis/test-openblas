#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhpcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhpcon_work)( /* LAPACKE_zhpcon_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zhpcon_work _g_LAPACKE_zhpcon_work = NULL;
lapack_int LAPACKE_zhpcon_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            ap,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zhpcon_work==NULL) {
        _g_LAPACKE_zhpcon_work = rindow_load_libopenblas_func("LAPACKE_zhpcon_work"); 
        if(_g_LAPACKE_zhpcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhpcon_work(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv,
        anorm,
        rcond,
        work    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsptrf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsptrf_work)( /* LAPACKE_dsptrf_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_dsptrf_work _g_LAPACKE_dsptrf_work = NULL;
lapack_int LAPACKE_dsptrf_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            ap,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_dsptrf_work==NULL) {
        _g_LAPACKE_dsptrf_work = rindow_load_libopenblas_func("LAPACKE_dsptrf_work"); 
        if(_g_LAPACKE_dsptrf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsptrf_work(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}

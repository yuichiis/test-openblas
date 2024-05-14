#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsptrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsptrd_work)( /* LAPACKE_dsptrd_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    double *            /* d */,
    double *            /* e */,
    double *            /* tau */
);
static PFNLAPACKE_dsptrd_work _g_LAPACKE_dsptrd_work = NULL;
lapack_int LAPACKE_dsptrd_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            ap,
    double *            d,
    double *            e,
    double *            tau
)
{
    if(_g_LAPACKE_dsptrd_work==NULL) {
        _g_LAPACKE_dsptrd_work = rindow_load_libopenblas_func("LAPACKE_dsptrd_work"); 
        if(_g_LAPACKE_dsptrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsptrd_work(
        matrix_layout,
        uplo,
        n,
        ap,
        d,
        e,
        tau    
    );
}

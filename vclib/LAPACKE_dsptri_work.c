#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsptri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsptri_work)( /* LAPACKE_dsptri_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    const lapack_int *            /* ipiv */,
    double *            /* work */
);
static PFNLAPACKE_dsptri_work _g_LAPACKE_dsptri_work = NULL;
lapack_int LAPACKE_dsptri_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            ap,
    const lapack_int *            ipiv,
    double *            work
)
{
    if(_g_LAPACKE_dsptri_work==NULL) {
        _g_LAPACKE_dsptri_work = rindow_load_libopenblas_func("LAPACKE_dsptri_work"); 
        if(_g_LAPACKE_dsptri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsptri_work(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv,
        work    
    );
}

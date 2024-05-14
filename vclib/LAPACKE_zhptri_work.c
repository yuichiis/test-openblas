#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhptri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhptri_work)( /* LAPACKE_zhptri_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    const lapack_int *            /* ipiv */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zhptri_work _g_LAPACKE_zhptri_work = NULL;
lapack_int LAPACKE_zhptri_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    const lapack_int *            ipiv,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zhptri_work==NULL) {
        _g_LAPACKE_zhptri_work = rindow_load_libopenblas_func("LAPACKE_zhptri_work"); 
        if(_g_LAPACKE_zhptri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhptri_work(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv,
        work    
    );
}

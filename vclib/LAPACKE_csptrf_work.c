#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csptrf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csptrf_work)( /* LAPACKE_csptrf_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_csptrf_work _g_LAPACKE_csptrf_work = NULL;
lapack_int LAPACKE_csptrf_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_csptrf_work==NULL) {
        _g_LAPACKE_csptrf_work = rindow_load_libopenblas_func("LAPACKE_csptrf_work"); 
        if(_g_LAPACKE_csptrf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csptrf_work(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}

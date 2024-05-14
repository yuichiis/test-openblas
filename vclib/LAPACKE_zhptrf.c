#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhptrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhptrf)( /* LAPACKE_zhptrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_zhptrf _g_LAPACKE_zhptrf = NULL;
lapack_int LAPACKE_zhptrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zhptrf==NULL) {
        _g_LAPACKE_zhptrf = rindow_load_libopenblas_func("LAPACKE_zhptrf"); 
        if(_g_LAPACKE_zhptrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhptrf(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsptrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsptrf)( /* LAPACKE_zsptrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_zsptrf _g_LAPACKE_zsptrf = NULL;
lapack_int LAPACKE_zsptrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zsptrf==NULL) {
        _g_LAPACKE_zsptrf = rindow_load_libopenblas_func("LAPACKE_zsptrf"); 
        if(_g_LAPACKE_zsptrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsptrf(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}

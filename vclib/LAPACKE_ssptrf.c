#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssptrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssptrf)( /* LAPACKE_ssptrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_ssptrf _g_LAPACKE_ssptrf = NULL;
lapack_int LAPACKE_ssptrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            ap,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_ssptrf==NULL) {
        _g_LAPACKE_ssptrf = rindow_load_libopenblas_func("LAPACKE_ssptrf"); 
        if(_g_LAPACKE_ssptrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssptrf(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}

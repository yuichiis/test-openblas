#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csptrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csptrf)( /* LAPACKE_csptrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_csptrf _g_LAPACKE_csptrf = NULL;
lapack_int LAPACKE_csptrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_csptrf==NULL) {
        _g_LAPACKE_csptrf = rindow_load_libopenblas_func("LAPACKE_csptrf"); 
        if(_g_LAPACKE_csptrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csptrf(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}

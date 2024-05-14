#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpptrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpptrf)( /* LAPACKE_dpptrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */
);
static PFNLAPACKE_dpptrf _g_LAPACKE_dpptrf = NULL;
lapack_int LAPACKE_dpptrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            ap
)
{
    if(_g_LAPACKE_dpptrf==NULL) {
        _g_LAPACKE_dpptrf = rindow_load_libopenblas_func("LAPACKE_dpptrf"); 
        if(_g_LAPACKE_dpptrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpptrf(
        matrix_layout,
        uplo,
        n,
        ap    
    );
}

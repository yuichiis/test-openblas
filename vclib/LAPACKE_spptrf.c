#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spptrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spptrf)( /* LAPACKE_spptrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */
);
static PFNLAPACKE_spptrf _g_LAPACKE_spptrf = NULL;
lapack_int LAPACKE_spptrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            ap
)
{
    if(_g_LAPACKE_spptrf==NULL) {
        _g_LAPACKE_spptrf = rindow_load_libopenblas_func("LAPACKE_spptrf"); 
        if(_g_LAPACKE_spptrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spptrf(
        matrix_layout,
        uplo,
        n,
        ap    
    );
}

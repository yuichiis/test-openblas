#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpftrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpftrf)( /* LAPACKE_dpftrf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */
);
static PFNLAPACKE_dpftrf _g_LAPACKE_dpftrf = NULL;
lapack_int LAPACKE_dpftrf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    double *            a
)
{
    if(_g_LAPACKE_dpftrf==NULL) {
        _g_LAPACKE_dpftrf = rindow_load_libopenblas_func("LAPACKE_dpftrf"); 
        if(_g_LAPACKE_dpftrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpftrf(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}

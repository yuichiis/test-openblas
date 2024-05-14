#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpttrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpttrf)( /* LAPACKE_zpttrf */
    lapack_int            /* n */,
    double *            /* d */,
    lapack_complex_double *            /* e */
);
static PFNLAPACKE_zpttrf _g_LAPACKE_zpttrf = NULL;
lapack_int LAPACKE_zpttrf(
    lapack_int            n,
    double *            d,
    lapack_complex_double *            e
)
{
    if(_g_LAPACKE_zpttrf==NULL) {
        _g_LAPACKE_zpttrf = rindow_load_libopenblas_func("LAPACKE_zpttrf"); 
        if(_g_LAPACKE_zpttrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpttrf(
        n,
        d,
        e    
    );
}

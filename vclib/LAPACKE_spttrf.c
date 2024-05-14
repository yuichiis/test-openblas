#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spttrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spttrf)( /* LAPACKE_spttrf */
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */
);
static PFNLAPACKE_spttrf _g_LAPACKE_spttrf = NULL;
lapack_int LAPACKE_spttrf(
    lapack_int            n,
    float *            d,
    float *            e
)
{
    if(_g_LAPACKE_spttrf==NULL) {
        _g_LAPACKE_spttrf = rindow_load_libopenblas_func("LAPACKE_spttrf"); 
        if(_g_LAPACKE_spttrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spttrf(
        n,
        d,
        e    
    );
}

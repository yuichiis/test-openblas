#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpttrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpttrf)( /* LAPACKE_cpttrf */
    lapack_int            /* n */,
    float *            /* d */,
    lapack_complex_float *            /* e */
);
static PFNLAPACKE_cpttrf _g_LAPACKE_cpttrf = NULL;
lapack_int LAPACKE_cpttrf(
    lapack_int            n,
    float *            d,
    lapack_complex_float *            e
)
{
    if(_g_LAPACKE_cpttrf==NULL) {
        _g_LAPACKE_cpttrf = rindow_load_libopenblas_func("LAPACKE_cpttrf"); 
        if(_g_LAPACKE_cpttrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpttrf(
        n,
        d,
        e    
    );
}

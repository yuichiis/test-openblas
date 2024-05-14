#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssterf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssterf)( /* LAPACKE_ssterf */
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */
);
static PFNLAPACKE_ssterf _g_LAPACKE_ssterf = NULL;
lapack_int LAPACKE_ssterf(
    lapack_int            n,
    float *            d,
    float *            e
)
{
    if(_g_LAPACKE_ssterf==NULL) {
        _g_LAPACKE_ssterf = rindow_load_libopenblas_func("LAPACKE_ssterf"); 
        if(_g_LAPACKE_ssterf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssterf(
        n,
        d,
        e    
    );
}

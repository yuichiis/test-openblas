#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlapy3 not found\n";
typedef double (CALLBACK* PFNLAPACKE_dlapy3)( /* LAPACKE_dlapy3 */
    double            /* x */,
    double            /* y */,
    double            /* z */
);
static PFNLAPACKE_dlapy3 _g_LAPACKE_dlapy3 = NULL;
double LAPACKE_dlapy3(
    double            x,
    double            y,
    double            z
)
{
    if(_g_LAPACKE_dlapy3==NULL) {
        _g_LAPACKE_dlapy3 = rindow_load_libopenblas_func("LAPACKE_dlapy3"); 
        if(_g_LAPACKE_dlapy3==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlapy3(
        x,
        y,
        z    
    );
}

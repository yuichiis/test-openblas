#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlapy2 not found\n";
typedef double (CALLBACK* PFNLAPACKE_dlapy2)( /* LAPACKE_dlapy2 */
    double            /* x */,
    double            /* y */
);
static PFNLAPACKE_dlapy2 _g_LAPACKE_dlapy2 = NULL;
double LAPACKE_dlapy2(
    double            x,
    double            y
)
{
    if(_g_LAPACKE_dlapy2==NULL) {
        _g_LAPACKE_dlapy2 = rindow_load_libopenblas_func("LAPACKE_dlapy2"); 
        if(_g_LAPACKE_dlapy2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlapy2(
        x,
        y    
    );
}

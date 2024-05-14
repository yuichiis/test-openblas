#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlartgs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlartgs)( /* LAPACKE_dlartgs */
    double            /* x */,
    double            /* y */,
    double            /* sigma */,
    double *            /* cs */,
    double *            /* sn */
);
static PFNLAPACKE_dlartgs _g_LAPACKE_dlartgs = NULL;
lapack_int LAPACKE_dlartgs(
    double            x,
    double            y,
    double            sigma,
    double *            cs,
    double *            sn
)
{
    if(_g_LAPACKE_dlartgs==NULL) {
        _g_LAPACKE_dlartgs = rindow_load_libopenblas_func("LAPACKE_dlartgs"); 
        if(_g_LAPACKE_dlartgs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlartgs(
        x,
        y,
        sigma,
        cs,
        sn    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slartgs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slartgs)( /* LAPACKE_slartgs */
    float            /* x */,
    float            /* y */,
    float            /* sigma */,
    float *            /* cs */,
    float *            /* sn */
);
static PFNLAPACKE_slartgs _g_LAPACKE_slartgs = NULL;
lapack_int LAPACKE_slartgs(
    float            x,
    float            y,
    float            sigma,
    float *            cs,
    float *            sn
)
{
    if(_g_LAPACKE_slartgs==NULL) {
        _g_LAPACKE_slartgs = rindow_load_libopenblas_func("LAPACKE_slartgs"); 
        if(_g_LAPACKE_slartgs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slartgs(
        x,
        y,
        sigma,
        cs,
        sn    
    );
}

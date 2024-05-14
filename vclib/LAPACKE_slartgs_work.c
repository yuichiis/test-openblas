#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slartgs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slartgs_work)( /* LAPACKE_slartgs_work */
    float            /* x */,
    float            /* y */,
    float            /* sigma */,
    float *            /* cs */,
    float *            /* sn */
);
static PFNLAPACKE_slartgs_work _g_LAPACKE_slartgs_work = NULL;
lapack_int LAPACKE_slartgs_work(
    float            x,
    float            y,
    float            sigma,
    float *            cs,
    float *            sn
)
{
    if(_g_LAPACKE_slartgs_work==NULL) {
        _g_LAPACKE_slartgs_work = rindow_load_libopenblas_func("LAPACKE_slartgs_work"); 
        if(_g_LAPACKE_slartgs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slartgs_work(
        x,
        y,
        sigma,
        cs,
        sn    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlartgs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlartgs_work)( /* LAPACKE_dlartgs_work */
    double            /* x */,
    double            /* y */,
    double            /* sigma */,
    double *            /* cs */,
    double *            /* sn */
);
static PFNLAPACKE_dlartgs_work _g_LAPACKE_dlartgs_work = NULL;
lapack_int LAPACKE_dlartgs_work(
    double            x,
    double            y,
    double            sigma,
    double *            cs,
    double *            sn
)
{
    if(_g_LAPACKE_dlartgs_work==NULL) {
        _g_LAPACKE_dlartgs_work = rindow_load_libopenblas_func("LAPACKE_dlartgs_work"); 
        if(_g_LAPACKE_dlartgs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlartgs_work(
        x,
        y,
        sigma,
        cs,
        sn    
    );
}

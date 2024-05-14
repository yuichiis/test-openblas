#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlartgp_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlartgp_work)( /* LAPACKE_dlartgp_work */
    double            /* f */,
    double            /* g */,
    double *            /* cs */,
    double *            /* sn */,
    double *            /* r */
);
static PFNLAPACKE_dlartgp_work _g_LAPACKE_dlartgp_work = NULL;
lapack_int LAPACKE_dlartgp_work(
    double            f,
    double            g,
    double *            cs,
    double *            sn,
    double *            r
)
{
    if(_g_LAPACKE_dlartgp_work==NULL) {
        _g_LAPACKE_dlartgp_work = rindow_load_libopenblas_func("LAPACKE_dlartgp_work"); 
        if(_g_LAPACKE_dlartgp_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlartgp_work(
        f,
        g,
        cs,
        sn,
        r    
    );
}

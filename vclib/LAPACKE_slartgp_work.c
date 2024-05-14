#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slartgp_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slartgp_work)( /* LAPACKE_slartgp_work */
    float            /* f */,
    float            /* g */,
    float *            /* cs */,
    float *            /* sn */,
    float *            /* r */
);
static PFNLAPACKE_slartgp_work _g_LAPACKE_slartgp_work = NULL;
lapack_int LAPACKE_slartgp_work(
    float            f,
    float            g,
    float *            cs,
    float *            sn,
    float *            r
)
{
    if(_g_LAPACKE_slartgp_work==NULL) {
        _g_LAPACKE_slartgp_work = rindow_load_libopenblas_func("LAPACKE_slartgp_work"); 
        if(_g_LAPACKE_slartgp_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slartgp_work(
        f,
        g,
        cs,
        sn,
        r    
    );
}

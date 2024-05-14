#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slartgp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slartgp)( /* LAPACKE_slartgp */
    float            /* f */,
    float            /* g */,
    float *            /* cs */,
    float *            /* sn */,
    float *            /* r */
);
static PFNLAPACKE_slartgp _g_LAPACKE_slartgp = NULL;
lapack_int LAPACKE_slartgp(
    float            f,
    float            g,
    float *            cs,
    float *            sn,
    float *            r
)
{
    if(_g_LAPACKE_slartgp==NULL) {
        _g_LAPACKE_slartgp = rindow_load_libopenblas_func("LAPACKE_slartgp"); 
        if(_g_LAPACKE_slartgp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slartgp(
        f,
        g,
        cs,
        sn,
        r    
    );
}

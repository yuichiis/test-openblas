#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slapy3_work not found\n";
typedef float (CALLBACK* PFNLAPACKE_slapy3_work)( /* LAPACKE_slapy3_work */
    float            /* x */,
    float            /* y */,
    float            /* z */
);
static PFNLAPACKE_slapy3_work _g_LAPACKE_slapy3_work = NULL;
float LAPACKE_slapy3_work(
    float            x,
    float            y,
    float            z
)
{
    if(_g_LAPACKE_slapy3_work==NULL) {
        _g_LAPACKE_slapy3_work = rindow_load_libopenblas_func("LAPACKE_slapy3_work"); 
        if(_g_LAPACKE_slapy3_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slapy3_work(
        x,
        y,
        z    
    );
}

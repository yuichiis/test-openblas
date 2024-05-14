#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slarfg not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slarfg)( /* LAPACKE_slarfg */
    lapack_int            /* n */,
    float *            /* alpha */,
    float *            /* x */,
    lapack_int            /* incx */,
    float *            /* tau */
);
static PFNLAPACKE_slarfg _g_LAPACKE_slarfg = NULL;
lapack_int LAPACKE_slarfg(
    lapack_int            n,
    float *            alpha,
    float *            x,
    lapack_int            incx,
    float *            tau
)
{
    if(_g_LAPACKE_slarfg==NULL) {
        _g_LAPACKE_slarfg = rindow_load_libopenblas_func("LAPACKE_slarfg"); 
        if(_g_LAPACKE_slarfg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slarfg(
        n,
        alpha,
        x,
        incx,
        tau    
    );
}

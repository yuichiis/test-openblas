#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlarfg not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlarfg)( /* LAPACKE_zlarfg */
    lapack_int            /* n */,
    lapack_complex_double *            /* alpha */,
    lapack_complex_double *            /* x */,
    lapack_int            /* incx */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zlarfg _g_LAPACKE_zlarfg = NULL;
lapack_int LAPACKE_zlarfg(
    lapack_int            n,
    lapack_complex_double *            alpha,
    lapack_complex_double *            x,
    lapack_int            incx,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zlarfg==NULL) {
        _g_LAPACKE_zlarfg = rindow_load_libopenblas_func("LAPACKE_zlarfg"); 
        if(_g_LAPACKE_zlarfg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlarfg(
        n,
        alpha,
        x,
        incx,
        tau    
    );
}

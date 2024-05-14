#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlarfg_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlarfg_work)( /* LAPACKE_dlarfg_work */
    lapack_int            /* n */,
    double *            /* alpha */,
    double *            /* x */,
    lapack_int            /* incx */,
    double *            /* tau */
);
static PFNLAPACKE_dlarfg_work _g_LAPACKE_dlarfg_work = NULL;
lapack_int LAPACKE_dlarfg_work(
    lapack_int            n,
    double *            alpha,
    double *            x,
    lapack_int            incx,
    double *            tau
)
{
    if(_g_LAPACKE_dlarfg_work==NULL) {
        _g_LAPACKE_dlarfg_work = rindow_load_libopenblas_func("LAPACKE_dlarfg_work"); 
        if(_g_LAPACKE_dlarfg_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlarfg_work(
        n,
        alpha,
        x,
        incx,
        tau    
    );
}

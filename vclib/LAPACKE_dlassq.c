#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlassq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlassq)( /* LAPACKE_dlassq */
    lapack_int            /* n */,
    double *            /* x */,
    lapack_int            /* incx */,
    double *            /* scale */,
    double *            /* sumsq */
);
static PFNLAPACKE_dlassq _g_LAPACKE_dlassq = NULL;
lapack_int LAPACKE_dlassq(
    lapack_int            n,
    double *            x,
    lapack_int            incx,
    double *            scale,
    double *            sumsq
)
{
    if(_g_LAPACKE_dlassq==NULL) {
        _g_LAPACKE_dlassq = rindow_load_libopenblas_func("LAPACKE_dlassq"); 
        if(_g_LAPACKE_dlassq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlassq(
        n,
        x,
        incx,
        scale,
        sumsq    
    );
}

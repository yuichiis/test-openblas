#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slassq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slassq)( /* LAPACKE_slassq */
    lapack_int            /* n */,
    float *            /* x */,
    lapack_int            /* incx */,
    float *            /* scale */,
    float *            /* sumsq */
);
static PFNLAPACKE_slassq _g_LAPACKE_slassq = NULL;
lapack_int LAPACKE_slassq(
    lapack_int            n,
    float *            x,
    lapack_int            incx,
    float *            scale,
    float *            sumsq
)
{
    if(_g_LAPACKE_slassq==NULL) {
        _g_LAPACKE_slassq = rindow_load_libopenblas_func("LAPACKE_slassq"); 
        if(_g_LAPACKE_slassq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slassq(
        n,
        x,
        incx,
        scale,
        sumsq    
    );
}

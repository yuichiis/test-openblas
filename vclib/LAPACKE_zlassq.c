#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlassq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlassq)( /* LAPACKE_zlassq */
    lapack_int            /* n */,
    lapack_complex_double *            /* x */,
    lapack_int            /* incx */,
    double *            /* scale */,
    double *            /* sumsq */
);
static PFNLAPACKE_zlassq _g_LAPACKE_zlassq = NULL;
lapack_int LAPACKE_zlassq(
    lapack_int            n,
    lapack_complex_double *            x,
    lapack_int            incx,
    double *            scale,
    double *            sumsq
)
{
    if(_g_LAPACKE_zlassq==NULL) {
        _g_LAPACKE_zlassq = rindow_load_libopenblas_func("LAPACKE_zlassq"); 
        if(_g_LAPACKE_zlassq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlassq(
        n,
        x,
        incx,
        scale,
        sumsq    
    );
}

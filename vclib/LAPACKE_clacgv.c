#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clacgv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clacgv)( /* LAPACKE_clacgv */
    lapack_int            /* n */,
    lapack_complex_float *            /* x */,
    lapack_int            /* incx */
);
static PFNLAPACKE_clacgv _g_LAPACKE_clacgv = NULL;
lapack_int LAPACKE_clacgv(
    lapack_int            n,
    lapack_complex_float *            x,
    lapack_int            incx
)
{
    if(_g_LAPACKE_clacgv==NULL) {
        _g_LAPACKE_clacgv = rindow_load_libopenblas_func("LAPACKE_clacgv"); 
        if(_g_LAPACKE_clacgv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clacgv(
        n,
        x,
        incx    
    );
}

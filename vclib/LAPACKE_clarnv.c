#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clarnv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clarnv)( /* LAPACKE_clarnv */
    lapack_int            /* idist */,
    lapack_int *            /* iseed */,
    lapack_int            /* n */,
    lapack_complex_float *            /* x */
);
static PFNLAPACKE_clarnv _g_LAPACKE_clarnv = NULL;
lapack_int LAPACKE_clarnv(
    lapack_int            idist,
    lapack_int *            iseed,
    lapack_int            n,
    lapack_complex_float *            x
)
{
    if(_g_LAPACKE_clarnv==NULL) {
        _g_LAPACKE_clarnv = rindow_load_libopenblas_func("LAPACKE_clarnv"); 
        if(_g_LAPACKE_clarnv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clarnv(
        idist,
        iseed,
        n,
        x    
    );
}

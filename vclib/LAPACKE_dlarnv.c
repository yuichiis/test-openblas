#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlarnv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlarnv)( /* LAPACKE_dlarnv */
    lapack_int            /* idist */,
    lapack_int *            /* iseed */,
    lapack_int            /* n */,
    double *            /* x */
);
static PFNLAPACKE_dlarnv _g_LAPACKE_dlarnv = NULL;
lapack_int LAPACKE_dlarnv(
    lapack_int            idist,
    lapack_int *            iseed,
    lapack_int            n,
    double *            x
)
{
    if(_g_LAPACKE_dlarnv==NULL) {
        _g_LAPACKE_dlarnv = rindow_load_libopenblas_func("LAPACKE_dlarnv"); 
        if(_g_LAPACKE_dlarnv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlarnv(
        idist,
        iseed,
        n,
        x    
    );
}

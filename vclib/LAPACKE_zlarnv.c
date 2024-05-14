#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlarnv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlarnv)( /* LAPACKE_zlarnv */
    lapack_int            /* idist */,
    lapack_int *            /* iseed */,
    lapack_int            /* n */,
    lapack_complex_double *            /* x */
);
static PFNLAPACKE_zlarnv _g_LAPACKE_zlarnv = NULL;
lapack_int LAPACKE_zlarnv(
    lapack_int            idist,
    lapack_int *            iseed,
    lapack_int            n,
    lapack_complex_double *            x
)
{
    if(_g_LAPACKE_zlarnv==NULL) {
        _g_LAPACKE_zlarnv = rindow_load_libopenblas_func("LAPACKE_zlarnv"); 
        if(_g_LAPACKE_zlarnv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlarnv(
        idist,
        iseed,
        n,
        x    
    );
}

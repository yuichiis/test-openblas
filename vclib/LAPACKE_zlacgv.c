#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlacgv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlacgv)( /* LAPACKE_zlacgv */
    lapack_int            /* n */,
    lapack_complex_double *            /* x */,
    lapack_int            /* incx */
);
static PFNLAPACKE_zlacgv _g_LAPACKE_zlacgv = NULL;
lapack_int LAPACKE_zlacgv(
    lapack_int            n,
    lapack_complex_double *            x,
    lapack_int            incx
)
{
    if(_g_LAPACKE_zlacgv==NULL) {
        _g_LAPACKE_zlacgv = rindow_load_libopenblas_func("LAPACKE_zlacgv"); 
        if(_g_LAPACKE_zlacgv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlacgv(
        n,
        x,
        incx    
    );
}

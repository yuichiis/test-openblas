#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slasrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slasrt)( /* LAPACKE_slasrt */
    char            /* id */,
    lapack_int            /* n */,
    float *            /* d */
);
static PFNLAPACKE_slasrt _g_LAPACKE_slasrt = NULL;
lapack_int LAPACKE_slasrt(
    char            id,
    lapack_int            n,
    float *            d
)
{
    if(_g_LAPACKE_slasrt==NULL) {
        _g_LAPACKE_slasrt = rindow_load_libopenblas_func("LAPACKE_slasrt"); 
        if(_g_LAPACKE_slasrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slasrt(
        id,
        n,
        d    
    );
}

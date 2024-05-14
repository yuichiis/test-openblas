#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ddisna not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ddisna)( /* LAPACKE_ddisna */
    char            /* job */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* d */,
    double *            /* sep */
);
static PFNLAPACKE_ddisna _g_LAPACKE_ddisna = NULL;
lapack_int LAPACKE_ddisna(
    char            job,
    lapack_int            m,
    lapack_int            n,
    const double *            d,
    double *            sep
)
{
    if(_g_LAPACKE_ddisna==NULL) {
        _g_LAPACKE_ddisna = rindow_load_libopenblas_func("LAPACKE_ddisna"); 
        if(_g_LAPACKE_ddisna==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ddisna(
        job,
        m,
        n,
        d,
        sep    
    );
}

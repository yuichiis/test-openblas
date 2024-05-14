#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sdisna not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sdisna)( /* LAPACKE_sdisna */
    char            /* job */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* d */,
    float *            /* sep */
);
static PFNLAPACKE_sdisna _g_LAPACKE_sdisna = NULL;
lapack_int LAPACKE_sdisna(
    char            job,
    lapack_int            m,
    lapack_int            n,
    const float *            d,
    float *            sep
)
{
    if(_g_LAPACKE_sdisna==NULL) {
        _g_LAPACKE_sdisna = rindow_load_libopenblas_func("LAPACKE_sdisna"); 
        if(_g_LAPACKE_sdisna==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sdisna(
        job,
        m,
        n,
        d,
        sep    
    );
}

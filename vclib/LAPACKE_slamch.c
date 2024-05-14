#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slamch not found\n";
typedef float (CALLBACK* PFNLAPACKE_slamch)( /* LAPACKE_slamch */
    char            /* cmach */
);
static PFNLAPACKE_slamch _g_LAPACKE_slamch = NULL;
float LAPACKE_slamch(
    char            cmach
)
{
    if(_g_LAPACKE_slamch==NULL) {
        _g_LAPACKE_slamch = rindow_load_libopenblas_func("LAPACKE_slamch"); 
        if(_g_LAPACKE_slamch==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slamch(
        cmach    
    );
}

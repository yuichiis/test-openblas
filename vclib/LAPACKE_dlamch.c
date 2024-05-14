#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlamch not found\n";
typedef double (CALLBACK* PFNLAPACKE_dlamch)( /* LAPACKE_dlamch */
    char            /* cmach */
);
static PFNLAPACKE_dlamch _g_LAPACKE_dlamch = NULL;
double LAPACKE_dlamch(
    char            cmach
)
{
    if(_g_LAPACKE_dlamch==NULL) {
        _g_LAPACKE_dlamch = rindow_load_libopenblas_func("LAPACKE_dlamch"); 
        if(_g_LAPACKE_dlamch==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlamch(
        cmach    
    );
}

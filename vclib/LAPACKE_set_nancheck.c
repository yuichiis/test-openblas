#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_set_nancheck not found\n";
typedef void (CALLBACK* PFNLAPACKE_set_nancheck)( /* LAPACKE_set_nancheck */
    int            /* flag */
);
static PFNLAPACKE_set_nancheck _g_LAPACKE_set_nancheck = NULL;
void LAPACKE_set_nancheck(
    int            flag
)
{
    if(_g_LAPACKE_set_nancheck==NULL) {
        _g_LAPACKE_set_nancheck = rindow_load_libopenblas_func("LAPACKE_set_nancheck"); 
        if(_g_LAPACKE_set_nancheck==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_LAPACKE_set_nancheck(
        flag    
    );
}

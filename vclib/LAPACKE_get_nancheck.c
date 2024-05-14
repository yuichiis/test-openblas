#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_get_nancheck not found\n";
typedef int (CALLBACK* PFNLAPACKE_get_nancheck)( /* LAPACKE_get_nancheck */
    void            /*  */
);
static PFNLAPACKE_get_nancheck _g_LAPACKE_get_nancheck = NULL;
int LAPACKE_get_nancheck(
    void            
)
{
    if(_g_LAPACKE_get_nancheck==NULL) {
        _g_LAPACKE_get_nancheck = rindow_load_libopenblas_func("LAPACKE_get_nancheck"); 
        if(_g_LAPACKE_get_nancheck==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_get_nancheck(
    
    );
}

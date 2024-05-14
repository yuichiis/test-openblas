#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ilaver not found\n";
typedef void (CALLBACK* PFNLAPACKE_ilaver)( /* LAPACKE_ilaver */
    lapack_int *            /* vers_major */,
    lapack_int *            /* vers_minor */,
    lapack_int *            /* vers_patch */
);
static PFNLAPACKE_ilaver _g_LAPACKE_ilaver = NULL;
void LAPACKE_ilaver(
    lapack_int *            vers_major,
    lapack_int *            vers_minor,
    lapack_int *            vers_patch
)
{
    if(_g_LAPACKE_ilaver==NULL) {
        _g_LAPACKE_ilaver = rindow_load_libopenblas_func("LAPACKE_ilaver"); 
        if(_g_LAPACKE_ilaver==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_LAPACKE_ilaver(
        vers_major,
        vers_minor,
        vers_patch    
    );
}

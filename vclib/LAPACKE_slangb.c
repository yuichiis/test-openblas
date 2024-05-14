#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slangb not found\n";
typedef float (CALLBACK* PFNLAPACKE_slangb)( /* LAPACKE_slangb */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const float *            /* ab */,
    lapack_int            /* ldab */
);
static PFNLAPACKE_slangb _g_LAPACKE_slangb = NULL;
float LAPACKE_slangb(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const float *            ab,
    lapack_int            ldab
)
{
    if(_g_LAPACKE_slangb==NULL) {
        _g_LAPACKE_slangb = rindow_load_libopenblas_func("LAPACKE_slangb"); 
        if(_g_LAPACKE_slangb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slangb(
        matrix_layout,
        norm,
        n,
        kl,
        ku,
        ab,
        ldab    
    );
}

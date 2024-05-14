#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlangb not found\n";
typedef double (CALLBACK* PFNLAPACKE_zlangb)( /* LAPACKE_zlangb */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */
);
static PFNLAPACKE_zlangb _g_LAPACKE_zlangb = NULL;
double LAPACKE_zlangb(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const lapack_complex_double *            ab,
    lapack_int            ldab
)
{
    if(_g_LAPACKE_zlangb==NULL) {
        _g_LAPACKE_zlangb = rindow_load_libopenblas_func("LAPACKE_zlangb"); 
        if(_g_LAPACKE_zlangb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlangb(
        matrix_layout,
        norm,
        n,
        kl,
        ku,
        ab,
        ldab    
    );
}

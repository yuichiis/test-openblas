#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpftrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpftrf)( /* LAPACKE_cpftrf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */
);
static PFNLAPACKE_cpftrf _g_LAPACKE_cpftrf = NULL;
lapack_int LAPACKE_cpftrf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a
)
{
    if(_g_LAPACKE_cpftrf==NULL) {
        _g_LAPACKE_cpftrf = rindow_load_libopenblas_func("LAPACKE_cpftrf"); 
        if(_g_LAPACKE_cpftrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpftrf(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}

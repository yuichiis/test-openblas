#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spftrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spftrf)( /* LAPACKE_spftrf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */
);
static PFNLAPACKE_spftrf _g_LAPACKE_spftrf = NULL;
lapack_int LAPACKE_spftrf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    float *            a
)
{
    if(_g_LAPACKE_spftrf==NULL) {
        _g_LAPACKE_spftrf = rindow_load_libopenblas_func("LAPACKE_spftrf"); 
        if(_g_LAPACKE_spftrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spftrf(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}

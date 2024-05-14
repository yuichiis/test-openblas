#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpbstf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpbstf)( /* LAPACKE_cpbstf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kb */,
    lapack_complex_float *            /* bb */,
    lapack_int            /* ldbb */
);
static PFNLAPACKE_cpbstf _g_LAPACKE_cpbstf = NULL;
lapack_int LAPACKE_cpbstf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kb,
    lapack_complex_float *            bb,
    lapack_int            ldbb
)
{
    if(_g_LAPACKE_cpbstf==NULL) {
        _g_LAPACKE_cpbstf = rindow_load_libopenblas_func("LAPACKE_cpbstf"); 
        if(_g_LAPACKE_cpbstf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpbstf(
        matrix_layout,
        uplo,
        n,
        kb,
        bb,
        ldbb    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbstf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbstf)( /* LAPACKE_spbstf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kb */,
    float *            /* bb */,
    lapack_int            /* ldbb */
);
static PFNLAPACKE_spbstf _g_LAPACKE_spbstf = NULL;
lapack_int LAPACKE_spbstf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kb,
    float *            bb,
    lapack_int            ldbb
)
{
    if(_g_LAPACKE_spbstf==NULL) {
        _g_LAPACKE_spbstf = rindow_load_libopenblas_func("LAPACKE_spbstf"); 
        if(_g_LAPACKE_spbstf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbstf(
        matrix_layout,
        uplo,
        n,
        kb,
        bb,
        ldbb    
    );
}

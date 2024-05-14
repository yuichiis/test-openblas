#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbstf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbstf)( /* LAPACKE_zpbstf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kb */,
    lapack_complex_double *            /* bb */,
    lapack_int            /* ldbb */
);
static PFNLAPACKE_zpbstf _g_LAPACKE_zpbstf = NULL;
lapack_int LAPACKE_zpbstf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kb,
    lapack_complex_double *            bb,
    lapack_int            ldbb
)
{
    if(_g_LAPACKE_zpbstf==NULL) {
        _g_LAPACKE_zpbstf = rindow_load_libopenblas_func("LAPACKE_zpbstf"); 
        if(_g_LAPACKE_zpbstf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbstf(
        matrix_layout,
        uplo,
        n,
        kb,
        bb,
        ldbb    
    );
}

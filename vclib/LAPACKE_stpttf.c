#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stpttf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stpttf)( /* LAPACKE_stpttf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* ap */,
    float *            /* arf */
);
static PFNLAPACKE_stpttf _g_LAPACKE_stpttf = NULL;
lapack_int LAPACKE_stpttf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const float *            ap,
    float *            arf
)
{
    if(_g_LAPACKE_stpttf==NULL) {
        _g_LAPACKE_stpttf = rindow_load_libopenblas_func("LAPACKE_stpttf"); 
        if(_g_LAPACKE_stpttf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stpttf(
        matrix_layout,
        transr,
        uplo,
        n,
        ap,
        arf    
    );
}

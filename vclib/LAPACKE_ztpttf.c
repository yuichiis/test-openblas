#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztpttf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztpttf)( /* LAPACKE_ztpttf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    lapack_complex_double *            /* arf */
);
static PFNLAPACKE_ztpttf _g_LAPACKE_ztpttf = NULL;
lapack_int LAPACKE_ztpttf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            ap,
    lapack_complex_double *            arf
)
{
    if(_g_LAPACKE_ztpttf==NULL) {
        _g_LAPACKE_ztpttf = rindow_load_libopenblas_func("LAPACKE_ztpttf"); 
        if(_g_LAPACKE_ztpttf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztpttf(
        matrix_layout,
        transr,
        uplo,
        n,
        ap,
        arf    
    );
}

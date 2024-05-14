#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctpttf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctpttf)( /* LAPACKE_ctpttf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    lapack_complex_float *            /* arf */
);
static PFNLAPACKE_ctpttf _g_LAPACKE_ctpttf = NULL;
lapack_int LAPACKE_ctpttf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            ap,
    lapack_complex_float *            arf
)
{
    if(_g_LAPACKE_ctpttf==NULL) {
        _g_LAPACKE_ctpttf = rindow_load_libopenblas_func("LAPACKE_ctpttf"); 
        if(_g_LAPACKE_ctpttf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctpttf(
        matrix_layout,
        transr,
        uplo,
        n,
        ap,
        arf    
    );
}

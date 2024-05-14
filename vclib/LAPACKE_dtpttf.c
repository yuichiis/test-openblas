#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtpttf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtpttf)( /* LAPACKE_dtpttf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* ap */,
    double *            /* arf */
);
static PFNLAPACKE_dtpttf _g_LAPACKE_dtpttf = NULL;
lapack_int LAPACKE_dtpttf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const double *            ap,
    double *            arf
)
{
    if(_g_LAPACKE_dtpttf==NULL) {
        _g_LAPACKE_dtpttf = rindow_load_libopenblas_func("LAPACKE_dtpttf"); 
        if(_g_LAPACKE_dtpttf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtpttf(
        matrix_layout,
        transr,
        uplo,
        n,
        ap,
        arf    
    );
}

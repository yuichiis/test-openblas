#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrttf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrttf)( /* LAPACKE_dtrttf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* arf */
);
static PFNLAPACKE_dtrttf _g_LAPACKE_dtrttf = NULL;
lapack_int LAPACKE_dtrttf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            arf
)
{
    if(_g_LAPACKE_dtrttf==NULL) {
        _g_LAPACKE_dtrttf = rindow_load_libopenblas_func("LAPACKE_dtrttf"); 
        if(_g_LAPACKE_dtrttf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrttf(
        matrix_layout,
        transr,
        uplo,
        n,
        a,
        lda,
        arf    
    );
}

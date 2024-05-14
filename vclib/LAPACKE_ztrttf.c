#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrttf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrttf)( /* LAPACKE_ztrttf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* arf */
);
static PFNLAPACKE_ztrttf _g_LAPACKE_ztrttf = NULL;
lapack_int LAPACKE_ztrttf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            arf
)
{
    if(_g_LAPACKE_ztrttf==NULL) {
        _g_LAPACKE_ztrttf = rindow_load_libopenblas_func("LAPACKE_ztrttf"); 
        if(_g_LAPACKE_ztrttf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrttf(
        matrix_layout,
        transr,
        uplo,
        n,
        a,
        lda,
        arf    
    );
}

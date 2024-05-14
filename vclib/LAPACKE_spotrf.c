#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spotrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spotrf)( /* LAPACKE_spotrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_spotrf _g_LAPACKE_spotrf = NULL;
lapack_int LAPACKE_spotrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_spotrf==NULL) {
        _g_LAPACKE_spotrf = rindow_load_libopenblas_func("LAPACKE_spotrf"); 
        if(_g_LAPACKE_spotrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spotrf(
        matrix_layout,
        uplo,
        n,
        a,
        lda    
    );
}

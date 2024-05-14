#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slansy not found\n";
typedef float (CALLBACK* PFNLAPACKE_slansy)( /* LAPACKE_slansy */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_slansy _g_LAPACKE_slansy = NULL;
float LAPACKE_slansy(
    int            matrix_layout,
    char            norm,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_slansy==NULL) {
        _g_LAPACKE_slansy = rindow_load_libopenblas_func("LAPACKE_slansy"); 
        if(_g_LAPACKE_slansy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slansy(
        matrix_layout,
        norm,
        uplo,
        n,
        a,
        lda    
    );
}

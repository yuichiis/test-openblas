#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clansy not found\n";
typedef float (CALLBACK* PFNLAPACKE_clansy)( /* LAPACKE_clansy */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_clansy _g_LAPACKE_clansy = NULL;
float LAPACKE_clansy(
    int            matrix_layout,
    char            norm,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_clansy==NULL) {
        _g_LAPACKE_clansy = rindow_load_libopenblas_func("LAPACKE_clansy"); 
        if(_g_LAPACKE_clansy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clansy(
        matrix_layout,
        norm,
        uplo,
        n,
        a,
        lda    
    );
}

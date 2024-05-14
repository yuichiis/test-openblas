#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clanhe not found\n";
typedef float (CALLBACK* PFNLAPACKE_clanhe)( /* LAPACKE_clanhe */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_clanhe _g_LAPACKE_clanhe = NULL;
float LAPACKE_clanhe(
    int            matrix_layout,
    char            norm,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_clanhe==NULL) {
        _g_LAPACKE_clanhe = rindow_load_libopenblas_func("LAPACKE_clanhe"); 
        if(_g_LAPACKE_clanhe==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clanhe(
        matrix_layout,
        norm,
        uplo,
        n,
        a,
        lda    
    );
}

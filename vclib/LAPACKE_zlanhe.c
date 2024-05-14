#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlanhe not found\n";
typedef double (CALLBACK* PFNLAPACKE_zlanhe)( /* LAPACKE_zlanhe */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_zlanhe _g_LAPACKE_zlanhe = NULL;
double LAPACKE_zlanhe(
    int            matrix_layout,
    char            norm,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_zlanhe==NULL) {
        _g_LAPACKE_zlanhe = rindow_load_libopenblas_func("LAPACKE_zlanhe"); 
        if(_g_LAPACKE_zlanhe==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlanhe(
        matrix_layout,
        norm,
        uplo,
        n,
        a,
        lda    
    );
}

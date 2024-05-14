#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clauum not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clauum)( /* LAPACKE_clauum */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_clauum _g_LAPACKE_clauum = NULL;
lapack_int LAPACKE_clauum(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_clauum==NULL) {
        _g_LAPACKE_clauum = rindow_load_libopenblas_func("LAPACKE_clauum"); 
        if(_g_LAPACKE_clauum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clauum(
        matrix_layout,
        uplo,
        n,
        a,
        lda    
    );
}

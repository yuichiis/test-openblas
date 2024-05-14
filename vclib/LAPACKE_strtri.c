#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strtri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strtri)( /* LAPACKE_strtri */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_strtri _g_LAPACKE_strtri = NULL;
lapack_int LAPACKE_strtri(
    int            matrix_layout,
    char            uplo,
    char            diag,
    lapack_int            n,
    float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_strtri==NULL) {
        _g_LAPACKE_strtri = rindow_load_libopenblas_func("LAPACKE_strtri"); 
        if(_g_LAPACKE_strtri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strtri(
        matrix_layout,
        uplo,
        diag,
        n,
        a,
        lda    
    );
}

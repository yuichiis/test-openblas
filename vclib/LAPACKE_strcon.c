#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strcon)( /* LAPACKE_strcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* rcond */
);
static PFNLAPACKE_strcon _g_LAPACKE_strcon = NULL;
lapack_int LAPACKE_strcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            rcond
)
{
    if(_g_LAPACKE_strcon==NULL) {
        _g_LAPACKE_strcon = rindow_load_libopenblas_func("LAPACKE_strcon"); 
        if(_g_LAPACKE_strcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strcon(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        a,
        lda,
        rcond    
    );
}

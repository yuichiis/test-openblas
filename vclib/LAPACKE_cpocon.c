#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpocon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpocon)( /* LAPACKE_cpocon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_cpocon _g_LAPACKE_cpocon = NULL;
lapack_int LAPACKE_cpocon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_cpocon==NULL) {
        _g_LAPACKE_cpocon = rindow_load_libopenblas_func("LAPACKE_cpocon"); 
        if(_g_LAPACKE_cpocon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpocon(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        anorm,
        rcond    
    );
}

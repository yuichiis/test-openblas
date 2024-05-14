#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spocon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spocon)( /* LAPACKE_spocon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_spocon _g_LAPACKE_spocon = NULL;
lapack_int LAPACKE_spocon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_spocon==NULL) {
        _g_LAPACKE_spocon = rindow_load_libopenblas_func("LAPACKE_spocon"); 
        if(_g_LAPACKE_spocon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spocon(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        anorm,
        rcond    
    );
}

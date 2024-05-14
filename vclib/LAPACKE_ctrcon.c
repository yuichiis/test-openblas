#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrcon)( /* LAPACKE_ctrcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* rcond */
);
static PFNLAPACKE_ctrcon _g_LAPACKE_ctrcon = NULL;
lapack_int LAPACKE_ctrcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    float *            rcond
)
{
    if(_g_LAPACKE_ctrcon==NULL) {
        _g_LAPACKE_ctrcon = rindow_load_libopenblas_func("LAPACKE_ctrcon"); 
        if(_g_LAPACKE_ctrcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrcon(
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

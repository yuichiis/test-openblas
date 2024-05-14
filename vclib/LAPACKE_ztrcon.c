#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrcon)( /* LAPACKE_ztrcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* rcond */
);
static PFNLAPACKE_ztrcon _g_LAPACKE_ztrcon = NULL;
lapack_int LAPACKE_ztrcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    double *            rcond
)
{
    if(_g_LAPACKE_ztrcon==NULL) {
        _g_LAPACKE_ztrcon = rindow_load_libopenblas_func("LAPACKE_ztrcon"); 
        if(_g_LAPACKE_ztrcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrcon(
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

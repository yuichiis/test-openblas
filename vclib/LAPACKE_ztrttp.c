#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrttp)( /* LAPACKE_ztrttp */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* ap */
);
static PFNLAPACKE_ztrttp _g_LAPACKE_ztrttp = NULL;
lapack_int LAPACKE_ztrttp(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            ap
)
{
    if(_g_LAPACKE_ztrttp==NULL) {
        _g_LAPACKE_ztrttp = rindow_load_libopenblas_func("LAPACKE_ztrttp"); 
        if(_g_LAPACKE_ztrttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrttp(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ap    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrttp)( /* LAPACKE_ctrttp */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* ap */
);
static PFNLAPACKE_ctrttp _g_LAPACKE_ctrttp = NULL;
lapack_int LAPACKE_ctrttp(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            ap
)
{
    if(_g_LAPACKE_ctrttp==NULL) {
        _g_LAPACKE_ctrttp = rindow_load_libopenblas_func("LAPACKE_ctrttp"); 
        if(_g_LAPACKE_ctrttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrttp(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ap    
    );
}

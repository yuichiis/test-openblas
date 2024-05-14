#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrttp)( /* LAPACKE_dtrttp */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* ap */
);
static PFNLAPACKE_dtrttp _g_LAPACKE_dtrttp = NULL;
lapack_int LAPACKE_dtrttp(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            ap
)
{
    if(_g_LAPACKE_dtrttp==NULL) {
        _g_LAPACKE_dtrttp = rindow_load_libopenblas_func("LAPACKE_dtrttp"); 
        if(_g_LAPACKE_dtrttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrttp(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ap    
    );
}

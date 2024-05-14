#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strttp)( /* LAPACKE_strttp */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* ap */
);
static PFNLAPACKE_strttp _g_LAPACKE_strttp = NULL;
lapack_int LAPACKE_strttp(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            ap
)
{
    if(_g_LAPACKE_strttp==NULL) {
        _g_LAPACKE_strttp = rindow_load_libopenblas_func("LAPACKE_strttp"); 
        if(_g_LAPACKE_strttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strttp(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ap    
    );
}

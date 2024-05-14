#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clacp2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clacp2)( /* LAPACKE_clacp2 */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_clacp2 _g_LAPACKE_clacp2 = NULL;
lapack_int LAPACKE_clacp2(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_clacp2==NULL) {
        _g_LAPACKE_clacp2 = rindow_load_libopenblas_func("LAPACKE_clacp2"); 
        if(_g_LAPACKE_clacp2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clacp2(
        matrix_layout,
        uplo,
        m,
        n,
        a,
        lda,
        b,
        ldb    
    );
}

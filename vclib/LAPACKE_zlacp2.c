#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlacp2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlacp2)( /* LAPACKE_zlacp2 */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zlacp2 _g_LAPACKE_zlacp2 = NULL;
lapack_int LAPACKE_zlacp2(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zlacp2==NULL) {
        _g_LAPACKE_zlacp2 = rindow_load_libopenblas_func("LAPACKE_zlacp2"); 
        if(_g_LAPACKE_zlacp2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlacp2(
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

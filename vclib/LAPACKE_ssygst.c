#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssygst not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssygst)( /* LAPACKE_ssygst */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_ssygst _g_LAPACKE_ssygst = NULL;
lapack_int LAPACKE_ssygst(
    int            matrix_layout,
    lapack_int            itype,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    const float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_ssygst==NULL) {
        _g_LAPACKE_ssygst = rindow_load_libopenblas_func("LAPACKE_ssygst"); 
        if(_g_LAPACKE_ssygst==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssygst(
        matrix_layout,
        itype,
        uplo,
        n,
        a,
        lda,
        b,
        ldb    
    );
}

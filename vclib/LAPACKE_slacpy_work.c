#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slacpy_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slacpy_work)( /* LAPACKE_slacpy_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_slacpy_work _g_LAPACKE_slacpy_work = NULL;
lapack_int LAPACKE_slacpy_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_slacpy_work==NULL) {
        _g_LAPACKE_slacpy_work = rindow_load_libopenblas_func("LAPACKE_slacpy_work"); 
        if(_g_LAPACKE_slacpy_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slacpy_work(
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

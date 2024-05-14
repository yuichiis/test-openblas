#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clacpy_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clacpy_work)( /* LAPACKE_clacpy_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_clacpy_work _g_LAPACKE_clacpy_work = NULL;
lapack_int LAPACKE_clacpy_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_clacpy_work==NULL) {
        _g_LAPACKE_clacpy_work = rindow_load_libopenblas_func("LAPACKE_clacpy_work"); 
        if(_g_LAPACKE_clacpy_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clacpy_work(
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

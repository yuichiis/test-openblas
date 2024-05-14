#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhegst not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhegst)( /* LAPACKE_zhegst */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zhegst _g_LAPACKE_zhegst = NULL;
lapack_int LAPACKE_zhegst(
    int            matrix_layout,
    lapack_int            itype,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zhegst==NULL) {
        _g_LAPACKE_zhegst = rindow_load_libopenblas_func("LAPACKE_zhegst"); 
        if(_g_LAPACKE_zhegst==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhegst(
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

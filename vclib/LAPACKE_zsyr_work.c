#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsyr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsyr_work)( /* LAPACKE_zsyr_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double            /* alpha */,
    const lapack_complex_double *            /* x */,
    lapack_int            /* incx */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_zsyr_work _g_LAPACKE_zsyr_work = NULL;
lapack_int LAPACKE_zsyr_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double            alpha,
    const lapack_complex_double *            x,
    lapack_int            incx,
    lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_zsyr_work==NULL) {
        _g_LAPACKE_zsyr_work = rindow_load_libopenblas_func("LAPACKE_zsyr_work"); 
        if(_g_LAPACKE_zsyr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsyr_work(
        matrix_layout,
        uplo,
        n,
        alpha,
        x,
        incx,
        a,
        lda    
    );
}

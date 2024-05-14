#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chetrf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chetrf_work)( /* LAPACKE_chetrf_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_chetrf_work _g_LAPACKE_chetrf_work = NULL;
lapack_int LAPACKE_chetrf_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            ipiv,
    lapack_complex_float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_chetrf_work==NULL) {
        _g_LAPACKE_chetrf_work = rindow_load_libopenblas_func("LAPACKE_chetrf_work"); 
        if(_g_LAPACKE_chetrf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chetrf_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ipiv,
        work,
        lwork    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssycon_3_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssycon_3_work)( /* LAPACKE_ssycon_3_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* e */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_ssycon_3_work _g_LAPACKE_ssycon_3_work = NULL;
lapack_int LAPACKE_ssycon_3_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const float *            e,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_ssycon_3_work==NULL) {
        _g_LAPACKE_ssycon_3_work = rindow_load_libopenblas_func("LAPACKE_ssycon_3_work"); 
        if(_g_LAPACKE_ssycon_3_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssycon_3_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        e,
        ipiv,
        anorm,
        rcond,
        work,
        iwork    
    );
}

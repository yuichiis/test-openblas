#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsytrs2_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsytrs2_work)( /* LAPACKE_dsytrs2_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* work */
);
static PFNLAPACKE_dsytrs2_work _g_LAPACKE_dsytrs2_work = NULL;
lapack_int LAPACKE_dsytrs2_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    double *            b,
    lapack_int            ldb,
    double *            work
)
{
    if(_g_LAPACKE_dsytrs2_work==NULL) {
        _g_LAPACKE_dsytrs2_work = rindow_load_libopenblas_func("LAPACKE_dsytrs2_work"); 
        if(_g_LAPACKE_dsytrs2_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsytrs2_work(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        ipiv,
        b,
        ldb,
        work    
    );
}

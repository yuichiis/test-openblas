#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zcgesv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zcgesv_work)( /* LAPACKE_zcgesv_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    lapack_complex_double *            /* work */,
    lapack_complex_float *            /* swork */,
    double *            /* rwork */,
    lapack_int *            /* iter */
);
static PFNLAPACKE_zcgesv_work _g_LAPACKE_zcgesv_work = NULL;
lapack_int LAPACKE_zcgesv_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int *            ipiv,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    lapack_complex_double *            work,
    lapack_complex_float *            swork,
    double *            rwork,
    lapack_int *            iter
)
{
    if(_g_LAPACKE_zcgesv_work==NULL) {
        _g_LAPACKE_zcgesv_work = rindow_load_libopenblas_func("LAPACKE_zcgesv_work"); 
        if(_g_LAPACKE_zcgesv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zcgesv_work(
        matrix_layout,
        n,
        nrhs,
        a,
        lda,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        work,
        swork,
        rwork,
        iter    
    );
}

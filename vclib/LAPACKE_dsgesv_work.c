#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsgesv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsgesv_work)( /* LAPACKE_dsgesv_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* work */,
    float *            /* swork */,
    lapack_int *            /* iter */
);
static PFNLAPACKE_dsgesv_work _g_LAPACKE_dsgesv_work = NULL;
lapack_int LAPACKE_dsgesv_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    double *            a,
    lapack_int            lda,
    lapack_int *            ipiv,
    double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            work,
    float *            swork,
    lapack_int *            iter
)
{
    if(_g_LAPACKE_dsgesv_work==NULL) {
        _g_LAPACKE_dsgesv_work = rindow_load_libopenblas_func("LAPACKE_dsgesv_work"); 
        if(_g_LAPACKE_dsgesv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsgesv_work(
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
        iter    
    );
}

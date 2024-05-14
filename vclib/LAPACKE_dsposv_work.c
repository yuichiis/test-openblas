#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsposv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsposv_work)( /* LAPACKE_dsposv_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* work */,
    float *            /* swork */,
    lapack_int *            /* iter */
);
static PFNLAPACKE_dsposv_work _g_LAPACKE_dsposv_work = NULL;
lapack_int LAPACKE_dsposv_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            work,
    float *            swork,
    lapack_int *            iter
)
{
    if(_g_LAPACKE_dsposv_work==NULL) {
        _g_LAPACKE_dsposv_work = rindow_load_libopenblas_func("LAPACKE_dsposv_work"); 
        if(_g_LAPACKE_dsposv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsposv_work(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb,
        x,
        ldx,
        work,
        swork,
        iter    
    );
}

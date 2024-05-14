#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgelsd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgelsd_work)( /* LAPACKE_cgelsd_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* s */,
    float            /* rcond */,
    lapack_int *            /* rank */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_cgelsd_work _g_LAPACKE_cgelsd_work = NULL;
lapack_int LAPACKE_cgelsd_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    float *            s,
    float            rcond,
    lapack_int *            rank,
    lapack_complex_float *            work,
    lapack_int            lwork,
    float *            rwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_cgelsd_work==NULL) {
        _g_LAPACKE_cgelsd_work = rindow_load_libopenblas_func("LAPACKE_cgelsd_work"); 
        if(_g_LAPACKE_cgelsd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgelsd_work(
        matrix_layout,
        m,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb,
        s,
        rcond,
        rank,
        work,
        lwork,
        rwork,
        iwork    
    );
}

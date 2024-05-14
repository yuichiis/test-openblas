#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgelss_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgelss_work)( /* LAPACKE_zgelss_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* s */,
    double            /* rcond */,
    lapack_int *            /* rank */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    double *            /* rwork */
);
static PFNLAPACKE_zgelss_work _g_LAPACKE_zgelss_work = NULL;
lapack_int LAPACKE_zgelss_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    double *            s,
    double            rcond,
    lapack_int *            rank,
    lapack_complex_double *            work,
    lapack_int            lwork,
    double *            rwork
)
{
    if(_g_LAPACKE_zgelss_work==NULL) {
        _g_LAPACKE_zgelss_work = rindow_load_libopenblas_func("LAPACKE_zgelss_work"); 
        if(_g_LAPACKE_zgelss_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgelss_work(
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
        rwork    
    );
}

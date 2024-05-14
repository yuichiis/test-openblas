#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dptsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dptsvx_work)( /* LAPACKE_dptsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* d */,
    const double *            /* e */,
    double *            /* df */,
    double *            /* ef */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */,
    double *            /* work */
);
static PFNLAPACKE_dptsvx_work _g_LAPACKE_dptsvx_work = NULL;
lapack_int LAPACKE_dptsvx_work(
    int            matrix_layout,
    char            fact,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            d,
    const double *            e,
    double *            df,
    double *            ef,
    const double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr,
    double *            work
)
{
    if(_g_LAPACKE_dptsvx_work==NULL) {
        _g_LAPACKE_dptsvx_work = rindow_load_libopenblas_func("LAPACKE_dptsvx_work"); 
        if(_g_LAPACKE_dptsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dptsvx_work(
        matrix_layout,
        fact,
        n,
        nrhs,
        d,
        e,
        df,
        ef,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr,
        work    
    );
}

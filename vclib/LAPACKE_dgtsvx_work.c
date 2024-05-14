#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgtsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgtsvx_work)( /* LAPACKE_dgtsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* dl */,
    const double *            /* d */,
    const double *            /* du */,
    double *            /* dlf */,
    double *            /* df */,
    double *            /* duf */,
    double *            /* du2 */,
    lapack_int *            /* ipiv */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dgtsvx_work _g_LAPACKE_dgtsvx_work = NULL;
lapack_int LAPACKE_dgtsvx_work(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            dl,
    const double *            d,
    const double *            du,
    double *            dlf,
    double *            df,
    double *            duf,
    double *            du2,
    lapack_int *            ipiv,
    const double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dgtsvx_work==NULL) {
        _g_LAPACKE_dgtsvx_work = rindow_load_libopenblas_func("LAPACKE_dgtsvx_work"); 
        if(_g_LAPACKE_dgtsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgtsvx_work(
        matrix_layout,
        fact,
        trans,
        n,
        nrhs,
        dl,
        d,
        du,
        dlf,
        df,
        duf,
        du2,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr,
        work,
        iwork    
    );
}

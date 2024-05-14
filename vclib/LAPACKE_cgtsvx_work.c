#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgtsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgtsvx_work)( /* LAPACKE_cgtsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* dl */,
    const lapack_complex_float *            /* d */,
    const lapack_complex_float *            /* du */,
    lapack_complex_float *            /* dlf */,
    lapack_complex_float *            /* df */,
    lapack_complex_float *            /* duf */,
    lapack_complex_float *            /* du2 */,
    lapack_int *            /* ipiv */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_cgtsvx_work _g_LAPACKE_cgtsvx_work = NULL;
lapack_int LAPACKE_cgtsvx_work(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            dl,
    const lapack_complex_float *            d,
    const lapack_complex_float *            du,
    lapack_complex_float *            dlf,
    lapack_complex_float *            df,
    lapack_complex_float *            duf,
    lapack_complex_float *            du2,
    lapack_int *            ipiv,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_cgtsvx_work==NULL) {
        _g_LAPACKE_cgtsvx_work = rindow_load_libopenblas_func("LAPACKE_cgtsvx_work"); 
        if(_g_LAPACKE_cgtsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgtsvx_work(
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
        rwork    
    );
}

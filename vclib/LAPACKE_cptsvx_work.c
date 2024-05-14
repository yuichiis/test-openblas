#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cptsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cptsvx_work)( /* LAPACKE_cptsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* d */,
    const lapack_complex_float *            /* e */,
    float *            /* df */,
    lapack_complex_float *            /* ef */,
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
static PFNLAPACKE_cptsvx_work _g_LAPACKE_cptsvx_work = NULL;
lapack_int LAPACKE_cptsvx_work(
    int            matrix_layout,
    char            fact,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            d,
    const lapack_complex_float *            e,
    float *            df,
    lapack_complex_float *            ef,
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
    if(_g_LAPACKE_cptsvx_work==NULL) {
        _g_LAPACKE_cptsvx_work = rindow_load_libopenblas_func("LAPACKE_cptsvx_work"); 
        if(_g_LAPACKE_cptsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cptsvx_work(
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
        work,
        rwork    
    );
}

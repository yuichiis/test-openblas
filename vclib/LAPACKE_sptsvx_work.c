#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sptsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sptsvx_work)( /* LAPACKE_sptsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* d */,
    const float *            /* e */,
    float *            /* df */,
    float *            /* ef */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */,
    float *            /* work */
);
static PFNLAPACKE_sptsvx_work _g_LAPACKE_sptsvx_work = NULL;
lapack_int LAPACKE_sptsvx_work(
    int            matrix_layout,
    char            fact,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            d,
    const float *            e,
    float *            df,
    float *            ef,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr,
    float *            work
)
{
    if(_g_LAPACKE_sptsvx_work==NULL) {
        _g_LAPACKE_sptsvx_work = rindow_load_libopenblas_func("LAPACKE_sptsvx_work"); 
        if(_g_LAPACKE_sptsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sptsvx_work(
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

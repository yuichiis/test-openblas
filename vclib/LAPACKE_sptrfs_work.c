#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sptrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sptrfs_work)( /* LAPACKE_sptrfs_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* d */,
    const float *            /* e */,
    const float *            /* df */,
    const float *            /* ef */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */,
    float *            /* work */
);
static PFNLAPACKE_sptrfs_work _g_LAPACKE_sptrfs_work = NULL;
lapack_int LAPACKE_sptrfs_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            d,
    const float *            e,
    const float *            df,
    const float *            ef,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr,
    float *            work
)
{
    if(_g_LAPACKE_sptrfs_work==NULL) {
        _g_LAPACKE_sptrfs_work = rindow_load_libopenblas_func("LAPACKE_sptrfs_work"); 
        if(_g_LAPACKE_sptrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sptrfs_work(
        matrix_layout,
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
        ferr,
        berr,
        work    
    );
}

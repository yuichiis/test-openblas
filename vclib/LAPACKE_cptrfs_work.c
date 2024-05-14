#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cptrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cptrfs_work)( /* LAPACKE_cptrfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* d */,
    const lapack_complex_float *            /* e */,
    const float *            /* df */,
    const lapack_complex_float *            /* ef */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_cptrfs_work _g_LAPACKE_cptrfs_work = NULL;
lapack_int LAPACKE_cptrfs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            d,
    const lapack_complex_float *            e,
    const float *            df,
    const lapack_complex_float *            ef,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_cptrfs_work==NULL) {
        _g_LAPACKE_cptrfs_work = rindow_load_libopenblas_func("LAPACKE_cptrfs_work"); 
        if(_g_LAPACKE_cptrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cptrfs_work(
        matrix_layout,
        uplo,
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
        work,
        rwork    
    );
}

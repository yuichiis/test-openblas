#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cptrfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cptrfs)( /* LAPACKE_cptrfs */
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
    float *            /* berr */
);
static PFNLAPACKE_cptrfs _g_LAPACKE_cptrfs = NULL;
lapack_int LAPACKE_cptrfs(
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
    float *            berr
)
{
    if(_g_LAPACKE_cptrfs==NULL) {
        _g_LAPACKE_cptrfs = rindow_load_libopenblas_func("LAPACKE_cptrfs"); 
        if(_g_LAPACKE_cptrfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cptrfs(
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
        berr    
    );
}

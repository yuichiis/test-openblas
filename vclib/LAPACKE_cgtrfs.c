#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgtrfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgtrfs)( /* LAPACKE_cgtrfs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* dl */,
    const lapack_complex_float *            /* d */,
    const lapack_complex_float *            /* du */,
    const lapack_complex_float *            /* dlf */,
    const lapack_complex_float *            /* df */,
    const lapack_complex_float *            /* duf */,
    const lapack_complex_float *            /* du2 */,
    const lapack_int *            /* ipiv */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_cgtrfs _g_LAPACKE_cgtrfs = NULL;
lapack_int LAPACKE_cgtrfs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            dl,
    const lapack_complex_float *            d,
    const lapack_complex_float *            du,
    const lapack_complex_float *            dlf,
    const lapack_complex_float *            df,
    const lapack_complex_float *            duf,
    const lapack_complex_float *            du2,
    const lapack_int *            ipiv,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_cgtrfs==NULL) {
        _g_LAPACKE_cgtrfs = rindow_load_libopenblas_func("LAPACKE_cgtrfs"); 
        if(_g_LAPACKE_cgtrfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgtrfs(
        matrix_layout,
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
        ferr,
        berr    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgtrfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgtrfs)( /* LAPACKE_zgtrfs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* dl */,
    const lapack_complex_double *            /* d */,
    const lapack_complex_double *            /* du */,
    const lapack_complex_double *            /* dlf */,
    const lapack_complex_double *            /* df */,
    const lapack_complex_double *            /* duf */,
    const lapack_complex_double *            /* du2 */,
    const lapack_int *            /* ipiv */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zgtrfs _g_LAPACKE_zgtrfs = NULL;
lapack_int LAPACKE_zgtrfs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            dl,
    const lapack_complex_double *            d,
    const lapack_complex_double *            du,
    const lapack_complex_double *            dlf,
    const lapack_complex_double *            df,
    const lapack_complex_double *            duf,
    const lapack_complex_double *            du2,
    const lapack_int *            ipiv,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zgtrfs==NULL) {
        _g_LAPACKE_zgtrfs = rindow_load_libopenblas_func("LAPACKE_zgtrfs"); 
        if(_g_LAPACKE_zgtrfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgtrfs(
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

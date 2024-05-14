#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgtsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgtsvx)( /* LAPACKE_zgtsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* dl */,
    const lapack_complex_double *            /* d */,
    const lapack_complex_double *            /* du */,
    lapack_complex_double *            /* dlf */,
    lapack_complex_double *            /* df */,
    lapack_complex_double *            /* duf */,
    lapack_complex_double *            /* du2 */,
    lapack_int *            /* ipiv */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zgtsvx _g_LAPACKE_zgtsvx = NULL;
lapack_int LAPACKE_zgtsvx(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            dl,
    const lapack_complex_double *            d,
    const lapack_complex_double *            du,
    lapack_complex_double *            dlf,
    lapack_complex_double *            df,
    lapack_complex_double *            duf,
    lapack_complex_double *            du2,
    lapack_int *            ipiv,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zgtsvx==NULL) {
        _g_LAPACKE_zgtsvx = rindow_load_libopenblas_func("LAPACKE_zgtsvx"); 
        if(_g_LAPACKE_zgtsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgtsvx(
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
        berr    
    );
}

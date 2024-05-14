#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgtsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgtsvx)( /* LAPACKE_dgtsvx */
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
    double *            /* berr */
);
static PFNLAPACKE_dgtsvx _g_LAPACKE_dgtsvx = NULL;
lapack_int LAPACKE_dgtsvx(
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
    double *            berr
)
{
    if(_g_LAPACKE_dgtsvx==NULL) {
        _g_LAPACKE_dgtsvx = rindow_load_libopenblas_func("LAPACKE_dgtsvx"); 
        if(_g_LAPACKE_dgtsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgtsvx(
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

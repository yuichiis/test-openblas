#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zptsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zptsvx)( /* LAPACKE_zptsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* d */,
    const lapack_complex_double *            /* e */,
    double *            /* df */,
    lapack_complex_double *            /* ef */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zptsvx _g_LAPACKE_zptsvx = NULL;
lapack_int LAPACKE_zptsvx(
    int            matrix_layout,
    char            fact,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            d,
    const lapack_complex_double *            e,
    double *            df,
    lapack_complex_double *            ef,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zptsvx==NULL) {
        _g_LAPACKE_zptsvx = rindow_load_libopenblas_func("LAPACKE_zptsvx"); 
        if(_g_LAPACKE_zptsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zptsvx(
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
        berr    
    );
}

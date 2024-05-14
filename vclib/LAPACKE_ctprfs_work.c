#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctprfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctprfs_work)( /* LAPACKE_ctprfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ap */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    const lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_ctprfs_work _g_LAPACKE_ctprfs_work = NULL;
lapack_int LAPACKE_ctprfs_work(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            ap,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    const lapack_complex_float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_ctprfs_work==NULL) {
        _g_LAPACKE_ctprfs_work = rindow_load_libopenblas_func("LAPACKE_ctprfs_work"); 
        if(_g_LAPACKE_ctprfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctprfs_work(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        nrhs,
        ap,
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

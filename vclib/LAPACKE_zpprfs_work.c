#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpprfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpprfs_work)( /* LAPACKE_zpprfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* ap */,
    const lapack_complex_double *            /* afp */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zpprfs_work _g_LAPACKE_zpprfs_work = NULL;
lapack_int LAPACKE_zpprfs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            ap,
    const lapack_complex_double *            afp,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zpprfs_work==NULL) {
        _g_LAPACKE_zpprfs_work = rindow_load_libopenblas_func("LAPACKE_zpprfs_work"); 
        if(_g_LAPACKE_zpprfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpprfs_work(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        afp,
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

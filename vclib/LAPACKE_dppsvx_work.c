#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dppsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dppsvx_work)( /* LAPACKE_dppsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* ap */,
    double *            /* afp */,
    char *            /* equed */,
    double *            /* s */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dppsvx_work _g_LAPACKE_dppsvx_work = NULL;
lapack_int LAPACKE_dppsvx_work(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    double *            ap,
    double *            afp,
    char *            equed,
    double *            s,
    double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dppsvx_work==NULL) {
        _g_LAPACKE_dppsvx_work = rindow_load_libopenblas_func("LAPACKE_dppsvx_work"); 
        if(_g_LAPACKE_dppsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dppsvx_work(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        ap,
        afp,
        equed,
        s,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr,
        work,
        iwork    
    );
}

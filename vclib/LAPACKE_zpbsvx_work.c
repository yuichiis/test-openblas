#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbsvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbsvx_work)( /* LAPACKE_zpbsvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_double *            /* afb */,
    lapack_int            /* ldafb */,
    char *            /* equed */,
    double *            /* s */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zpbsvx_work _g_LAPACKE_zpbsvx_work = NULL;
lapack_int LAPACKE_zpbsvx_work(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    lapack_complex_double *            ab,
    lapack_int            ldab,
    lapack_complex_double *            afb,
    lapack_int            ldafb,
    char *            equed,
    double *            s,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zpbsvx_work==NULL) {
        _g_LAPACKE_zpbsvx_work = rindow_load_libopenblas_func("LAPACKE_zpbsvx_work"); 
        if(_g_LAPACKE_zpbsvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbsvx_work(
        matrix_layout,
        fact,
        uplo,
        n,
        kd,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
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
        rwork    
    );
}

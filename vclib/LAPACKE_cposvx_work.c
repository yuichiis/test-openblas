#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cposvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cposvx_work)( /* LAPACKE_cposvx_work */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* af */,
    lapack_int            /* ldaf */,
    char *            /* equed */,
    float *            /* s */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_cposvx_work _g_LAPACKE_cposvx_work = NULL;
lapack_int LAPACKE_cposvx_work(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            af,
    lapack_int            ldaf,
    char *            equed,
    float *            s,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_cposvx_work==NULL) {
        _g_LAPACKE_cposvx_work = rindow_load_libopenblas_func("LAPACKE_cposvx_work"); 
        if(_g_LAPACKE_cposvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cposvx_work(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
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

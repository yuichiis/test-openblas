#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctbrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctbrfs_work)( /* LAPACKE_ctbrfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    const lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_ctbrfs_work _g_LAPACKE_ctbrfs_work = NULL;
lapack_int LAPACKE_ctbrfs_work(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
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
    if(_g_LAPACKE_ctbrfs_work==NULL) {
        _g_LAPACKE_ctbrfs_work = rindow_load_libopenblas_func("LAPACKE_ctbrfs_work"); 
        if(_g_LAPACKE_ctbrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctbrfs_work(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        kd,
        nrhs,
        ab,
        ldab,
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

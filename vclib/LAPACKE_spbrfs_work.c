#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbrfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbrfs_work)( /* LAPACKE_spbrfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    const float *            /* afb */,
    lapack_int            /* ldafb */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_spbrfs_work _g_LAPACKE_spbrfs_work = NULL;
lapack_int LAPACKE_spbrfs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const float *            ab,
    lapack_int            ldab,
    const float *            afb,
    lapack_int            ldafb,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_spbrfs_work==NULL) {
        _g_LAPACKE_spbrfs_work = rindow_load_libopenblas_func("LAPACKE_spbrfs_work"); 
        if(_g_LAPACKE_spbrfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbrfs_work(
        matrix_layout,
        uplo,
        n,
        kd,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr,
        work,
        iwork    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spprfs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spprfs_work)( /* LAPACKE_spprfs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* ap */,
    const float *            /* afp */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_spprfs_work _g_LAPACKE_spprfs_work = NULL;
lapack_int LAPACKE_spprfs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            ap,
    const float *            afp,
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
    if(_g_LAPACKE_spprfs_work==NULL) {
        _g_LAPACKE_spprfs_work = rindow_load_libopenblas_func("LAPACKE_spprfs_work"); 
        if(_g_LAPACKE_spprfs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spprfs_work(
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
        iwork    
    );
}

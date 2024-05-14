#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dspevd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dspevd_work)( /* LAPACKE_dspevd_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_dspevd_work _g_LAPACKE_dspevd_work = NULL;
lapack_int LAPACKE_dspevd_work(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    double *            ap,
    double *            w,
    double *            z,
    lapack_int            ldz,
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_dspevd_work==NULL) {
        _g_LAPACKE_dspevd_work = rindow_load_libopenblas_func("LAPACKE_dspevd_work"); 
        if(_g_LAPACKE_dspevd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dspevd_work(
        matrix_layout,
        jobz,
        uplo,
        n,
        ap,
        w,
        z,
        ldz,
        work,
        lwork,
        iwork,
        liwork    
    );
}

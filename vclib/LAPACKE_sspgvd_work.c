#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sspgvd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sspgvd_work)( /* LAPACKE_sspgvd_work */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    float *            /* bp */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_sspgvd_work _g_LAPACKE_sspgvd_work = NULL;
lapack_int LAPACKE_sspgvd_work(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    float *            ap,
    float *            bp,
    float *            w,
    float *            z,
    lapack_int            ldz,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_sspgvd_work==NULL) {
        _g_LAPACKE_sspgvd_work = rindow_load_libopenblas_func("LAPACKE_sspgvd_work"); 
        if(_g_LAPACKE_sspgvd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sspgvd_work(
        matrix_layout,
        itype,
        jobz,
        uplo,
        n,
        ap,
        bp,
        w,
        z,
        ldz,
        work,
        lwork,
        iwork,
        liwork    
    );
}

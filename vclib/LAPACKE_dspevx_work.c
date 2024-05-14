#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dspevx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dspevx_work)( /* LAPACKE_dspevx_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    double            /* abstol */,
    lapack_int *            /* m */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */,
    double *            /* work */,
    lapack_int *            /* iwork */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_dspevx_work _g_LAPACKE_dspevx_work = NULL;
lapack_int LAPACKE_dspevx_work(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    double *            ap,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    double            abstol,
    lapack_int *            m,
    double *            w,
    double *            z,
    lapack_int            ldz,
    double *            work,
    lapack_int *            iwork,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_dspevx_work==NULL) {
        _g_LAPACKE_dspevx_work = rindow_load_libopenblas_func("LAPACKE_dspevx_work"); 
        if(_g_LAPACKE_dspevx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dspevx_work(
        matrix_layout,
        jobz,
        range,
        uplo,
        n,
        ap,
        vl,
        vu,
        il,
        iu,
        abstol,
        m,
        w,
        z,
        ldz,
        work,
        iwork,
        ifail    
    );
}

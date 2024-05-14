#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dstemr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dstemr_work)( /* LAPACKE_dstemr_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* m */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int            /* nzc */,
    lapack_int *            /* isuppz */,
    lapack_logical *            /* tryrac */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_dstemr_work _g_LAPACKE_dstemr_work = NULL;
lapack_int LAPACKE_dstemr_work(
    int            matrix_layout,
    char            jobz,
    char            range,
    lapack_int            n,
    double *            d,
    double *            e,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            m,
    double *            w,
    double *            z,
    lapack_int            ldz,
    lapack_int            nzc,
    lapack_int *            isuppz,
    lapack_logical *            tryrac,
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_dstemr_work==NULL) {
        _g_LAPACKE_dstemr_work = rindow_load_libopenblas_func("LAPACKE_dstemr_work"); 
        if(_g_LAPACKE_dstemr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dstemr_work(
        matrix_layout,
        jobz,
        range,
        n,
        d,
        e,
        vl,
        vu,
        il,
        iu,
        m,
        w,
        z,
        ldz,
        nzc,
        isuppz,
        tryrac,
        work,
        lwork,
        iwork,
        liwork    
    );
}

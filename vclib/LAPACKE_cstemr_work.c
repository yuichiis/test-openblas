#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cstemr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cstemr_work)( /* LAPACKE_cstemr_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* m */,
    float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int            /* nzc */,
    lapack_int *            /* isuppz */,
    lapack_logical *            /* tryrac */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_cstemr_work _g_LAPACKE_cstemr_work = NULL;
lapack_int LAPACKE_cstemr_work(
    int            matrix_layout,
    char            jobz,
    char            range,
    lapack_int            n,
    float *            d,
    float *            e,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            m,
    float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_int            nzc,
    lapack_int *            isuppz,
    lapack_logical *            tryrac,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_cstemr_work==NULL) {
        _g_LAPACKE_cstemr_work = rindow_load_libopenblas_func("LAPACKE_cstemr_work"); 
        if(_g_LAPACKE_cstemr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cstemr_work(
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

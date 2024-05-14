#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sstevx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sstevx_work)( /* LAPACKE_sstevx_work */
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
    float            /* abstol */,
    lapack_int *            /* m */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* work */,
    lapack_int *            /* iwork */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_sstevx_work _g_LAPACKE_sstevx_work = NULL;
lapack_int LAPACKE_sstevx_work(
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
    float            abstol,
    lapack_int *            m,
    float *            w,
    float *            z,
    lapack_int            ldz,
    float *            work,
    lapack_int *            iwork,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_sstevx_work==NULL) {
        _g_LAPACKE_sstevx_work = rindow_load_libopenblas_func("LAPACKE_sstevx_work"); 
        if(_g_LAPACKE_sstevx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sstevx_work(
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

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sspgvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sspgvx_work)( /* LAPACKE_sspgvx_work */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    float *            /* bp */,
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
static PFNLAPACKE_sspgvx_work _g_LAPACKE_sspgvx_work = NULL;
lapack_int LAPACKE_sspgvx_work(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    float *            ap,
    float *            bp,
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
    if(_g_LAPACKE_sspgvx_work==NULL) {
        _g_LAPACKE_sspgvx_work = rindow_load_libopenblas_func("LAPACKE_sspgvx_work"); 
        if(_g_LAPACKE_sspgvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sspgvx_work(
        matrix_layout,
        itype,
        jobz,
        range,
        uplo,
        n,
        ap,
        bp,
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

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chpgvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chpgvx_work)( /* LAPACKE_chpgvx_work */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    lapack_complex_float *            /* bp */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    float            /* abstol */,
    lapack_int *            /* m */,
    float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */,
    lapack_int *            /* iwork */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_chpgvx_work _g_LAPACKE_chpgvx_work = NULL;
lapack_int LAPACKE_chpgvx_work(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    lapack_complex_float *            bp,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    float            abstol,
    lapack_int *            m,
    float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_complex_float *            work,
    float *            rwork,
    lapack_int *            iwork,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_chpgvx_work==NULL) {
        _g_LAPACKE_chpgvx_work = rindow_load_libopenblas_func("LAPACKE_chpgvx_work"); 
        if(_g_LAPACKE_chpgvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chpgvx_work(
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
        rwork,
        iwork,
        ifail    
    );
}

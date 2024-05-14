#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chbgvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chbgvx_work)( /* LAPACKE_chbgvx_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_float *            /* bb */,
    lapack_int            /* ldbb */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
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
static PFNLAPACKE_chbgvx_work _g_LAPACKE_chbgvx_work = NULL;
lapack_int LAPACKE_chbgvx_work(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    lapack_complex_float *            bb,
    lapack_int            ldbb,
    lapack_complex_float *            q,
    lapack_int            ldq,
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
    if(_g_LAPACKE_chbgvx_work==NULL) {
        _g_LAPACKE_chbgvx_work = rindow_load_libopenblas_func("LAPACKE_chbgvx_work"); 
        if(_g_LAPACKE_chbgvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chbgvx_work(
        matrix_layout,
        jobz,
        range,
        uplo,
        n,
        ka,
        kb,
        ab,
        ldab,
        bb,
        ldbb,
        q,
        ldq,
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

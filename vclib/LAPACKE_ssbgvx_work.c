#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssbgvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssbgvx_work)( /* LAPACKE_ssbgvx_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* bb */,
    lapack_int            /* ldbb */,
    float *            /* q */,
    lapack_int            /* ldq */,
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
static PFNLAPACKE_ssbgvx_work _g_LAPACKE_ssbgvx_work = NULL;
lapack_int LAPACKE_ssbgvx_work(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    float *            ab,
    lapack_int            ldab,
    float *            bb,
    lapack_int            ldbb,
    float *            q,
    lapack_int            ldq,
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
    if(_g_LAPACKE_ssbgvx_work==NULL) {
        _g_LAPACKE_ssbgvx_work = rindow_load_libopenblas_func("LAPACKE_ssbgvx_work"); 
        if(_g_LAPACKE_ssbgvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssbgvx_work(
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
        iwork,
        ifail    
    );
}

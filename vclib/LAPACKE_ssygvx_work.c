#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssygvx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssygvx_work)( /* LAPACKE_ssygvx_work */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
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
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_ssygvx_work _g_LAPACKE_ssygvx_work = NULL;
lapack_int LAPACKE_ssygvx_work(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
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
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_ssygvx_work==NULL) {
        _g_LAPACKE_ssygvx_work = rindow_load_libopenblas_func("LAPACKE_ssygvx_work"); 
        if(_g_LAPACKE_ssygvx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssygvx_work(
        matrix_layout,
        itype,
        jobz,
        range,
        uplo,
        n,
        a,
        lda,
        b,
        ldb,
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
        lwork,
        iwork,
        ifail    
    );
}

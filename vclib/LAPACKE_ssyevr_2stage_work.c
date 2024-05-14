#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssyevr_2stage_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssyevr_2stage_work)( /* LAPACKE_ssyevr_2stage_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    float            /* abstol */,
    lapack_int *            /* m */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* isuppz */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_ssyevr_2stage_work _g_LAPACKE_ssyevr_2stage_work = NULL;
lapack_int LAPACKE_ssyevr_2stage_work(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    float            abstol,
    lapack_int *            m,
    float *            w,
    float *            z,
    lapack_int            ldz,
    lapack_int *            isuppz,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_ssyevr_2stage_work==NULL) {
        _g_LAPACKE_ssyevr_2stage_work = rindow_load_libopenblas_func("LAPACKE_ssyevr_2stage_work"); 
        if(_g_LAPACKE_ssyevr_2stage_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssyevr_2stage_work(
        matrix_layout,
        jobz,
        range,
        uplo,
        n,
        a,
        lda,
        vl,
        vu,
        il,
        iu,
        abstol,
        m,
        w,
        z,
        ldz,
        isuppz,
        work,
        lwork,
        iwork,
        liwork    
    );
}

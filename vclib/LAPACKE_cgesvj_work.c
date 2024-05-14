#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgesvj_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgesvj_work)( /* LAPACKE_cgesvj_work */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* sva */,
    lapack_int            /* mv */,
    lapack_complex_float *            /* v */,
    lapack_int            /* ldv */,
    lapack_complex_float *            /* cwork */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_int            /* lrwork */
);
static PFNLAPACKE_cgesvj_work _g_LAPACKE_cgesvj_work = NULL;
lapack_int LAPACKE_cgesvj_work(
    int            matrix_layout,
    char            joba,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float *            sva,
    lapack_int            mv,
    lapack_complex_float *            v,
    lapack_int            ldv,
    lapack_complex_float *            cwork,
    lapack_int            lwork,
    float *            rwork,
    lapack_int            lrwork
)
{
    if(_g_LAPACKE_cgesvj_work==NULL) {
        _g_LAPACKE_cgesvj_work = rindow_load_libopenblas_func("LAPACKE_cgesvj_work"); 
        if(_g_LAPACKE_cgesvj_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgesvj_work(
        matrix_layout,
        joba,
        jobu,
        jobv,
        m,
        n,
        a,
        lda,
        sva,
        mv,
        v,
        ldv,
        cwork,
        lwork,
        rwork,
        lrwork    
    );
}

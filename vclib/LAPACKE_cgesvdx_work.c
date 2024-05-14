#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgesvdx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgesvdx_work)( /* LAPACKE_cgesvdx_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobvt */,
    char            /* range */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* ns */,
    float *            /* s */,
    lapack_complex_float *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_float *            /* vt */,
    lapack_int            /* ldvt */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_cgesvdx_work _g_LAPACKE_cgesvdx_work = NULL;
lapack_int LAPACKE_cgesvdx_work(
    int            matrix_layout,
    char            jobu,
    char            jobvt,
    char            range,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            ns,
    float *            s,
    lapack_complex_float *            u,
    lapack_int            ldu,
    lapack_complex_float *            vt,
    lapack_int            ldvt,
    lapack_complex_float *            work,
    lapack_int            lwork,
    float *            rwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_cgesvdx_work==NULL) {
        _g_LAPACKE_cgesvdx_work = rindow_load_libopenblas_func("LAPACKE_cgesvdx_work"); 
        if(_g_LAPACKE_cgesvdx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgesvdx_work(
        matrix_layout,
        jobu,
        jobvt,
        range,
        m,
        n,
        a,
        lda,
        vl,
        vu,
        il,
        iu,
        ns,
        s,
        u,
        ldu,
        vt,
        ldvt,
        work,
        lwork,
        rwork,
        iwork    
    );
}

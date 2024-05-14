#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesvdx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesvdx_work)( /* LAPACKE_sgesvdx_work */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobvt */,
    char            /* range */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* ns */,
    float *            /* s */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* vt */,
    lapack_int            /* ldvt */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sgesvdx_work _g_LAPACKE_sgesvdx_work = NULL;
lapack_int LAPACKE_sgesvdx_work(
    int            matrix_layout,
    char            jobu,
    char            jobvt,
    char            range,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            ns,
    float *            s,
    float *            u,
    lapack_int            ldu,
    float *            vt,
    lapack_int            ldvt,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_sgesvdx_work==NULL) {
        _g_LAPACKE_sgesvdx_work = rindow_load_libopenblas_func("LAPACKE_sgesvdx_work"); 
        if(_g_LAPACKE_sgesvdx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesvdx_work(
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
        iwork    
    );
}

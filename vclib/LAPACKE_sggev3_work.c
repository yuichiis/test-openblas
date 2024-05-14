#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggev3_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggev3_work)( /* LAPACKE_sggev3_work */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* alphar */,
    float *            /* alphai */,
    float *            /* beta */,
    float *            /* vl */,
    lapack_int            /* ldvl */,
    float *            /* vr */,
    lapack_int            /* ldvr */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sggev3_work _g_LAPACKE_sggev3_work = NULL;
lapack_int LAPACKE_sggev3_work(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            alphar,
    float *            alphai,
    float *            beta,
    float *            vl,
    lapack_int            ldvl,
    float *            vr,
    lapack_int            ldvr,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sggev3_work==NULL) {
        _g_LAPACKE_sggev3_work = rindow_load_libopenblas_func("LAPACKE_sggev3_work"); 
        if(_g_LAPACKE_sggev3_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggev3_work(
        matrix_layout,
        jobvl,
        jobvr,
        n,
        a,
        lda,
        b,
        ldb,
        alphar,
        alphai,
        beta,
        vl,
        ldvl,
        vr,
        ldvr,
        work,
        lwork    
    );
}

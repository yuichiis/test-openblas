#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesdd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesdd_work)( /* LAPACKE_sgesdd_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* vt */,
    lapack_int            /* ldvt */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sgesdd_work _g_LAPACKE_sgesdd_work = NULL;
lapack_int LAPACKE_sgesdd_work(
    int            matrix_layout,
    char            jobz,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
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
    if(_g_LAPACKE_sgesdd_work==NULL) {
        _g_LAPACKE_sgesdd_work = rindow_load_libopenblas_func("LAPACKE_sgesdd_work"); 
        if(_g_LAPACKE_sgesdd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesdd_work(
        matrix_layout,
        jobz,
        m,
        n,
        a,
        lda,
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

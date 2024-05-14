#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgejsv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgejsv_work)( /* LAPACKE_zgejsv_work */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobr */,
    char            /* jobt */,
    char            /* jobp */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* sva */,
    lapack_complex_double *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    lapack_complex_double *            /* cwork */,
    lapack_int            /* lwork */,
    double *            /* work */,
    lapack_int            /* lrwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_zgejsv_work _g_LAPACKE_zgejsv_work = NULL;
lapack_int LAPACKE_zgejsv_work(
    int            matrix_layout,
    char            joba,
    char            jobu,
    char            jobv,
    char            jobr,
    char            jobt,
    char            jobp,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            sva,
    lapack_complex_double *            u,
    lapack_int            ldu,
    lapack_complex_double *            v,
    lapack_int            ldv,
    lapack_complex_double *            cwork,
    lapack_int            lwork,
    double *            work,
    lapack_int            lrwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_zgejsv_work==NULL) {
        _g_LAPACKE_zgejsv_work = rindow_load_libopenblas_func("LAPACKE_zgejsv_work"); 
        if(_g_LAPACKE_zgejsv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgejsv_work(
        matrix_layout,
        joba,
        jobu,
        jobv,
        jobr,
        jobt,
        jobp,
        m,
        n,
        a,
        lda,
        sva,
        u,
        ldu,
        v,
        ldv,
        cwork,
        lwork,
        work,
        lrwork,
        iwork    
    );
}

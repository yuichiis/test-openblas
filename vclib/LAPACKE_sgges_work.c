#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgges_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgges_work)( /* LAPACKE_sgges_work */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_S_SELECT3            /* selctg */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    float *            /* alphar */,
    float *            /* alphai */,
    float *            /* beta */,
    float *            /* vsl */,
    lapack_int            /* ldvsl */,
    float *            /* vsr */,
    lapack_int            /* ldvsr */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_sgges_work _g_LAPACKE_sgges_work = NULL;
lapack_int LAPACKE_sgges_work(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_S_SELECT3            selctg,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    float *            alphar,
    float *            alphai,
    float *            beta,
    float *            vsl,
    lapack_int            ldvsl,
    float *            vsr,
    lapack_int            ldvsr,
    float *            work,
    lapack_int            lwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_sgges_work==NULL) {
        _g_LAPACKE_sgges_work = rindow_load_libopenblas_func("LAPACKE_sgges_work"); 
        if(_g_LAPACKE_sgges_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgges_work(
        matrix_layout,
        jobvsl,
        jobvsr,
        sort,
        selctg,
        n,
        a,
        lda,
        b,
        ldb,
        sdim,
        alphar,
        alphai,
        beta,
        vsl,
        ldvsl,
        vsr,
        ldvsr,
        work,
        lwork,
        bwork    
    );
}

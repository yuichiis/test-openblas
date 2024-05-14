#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggesx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggesx_work)( /* LAPACKE_sggesx_work */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_S_SELECT3            /* selctg */,
    char            /* sense */,
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
    float *            /* rconde */,
    float *            /* rcondv */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_sggesx_work _g_LAPACKE_sggesx_work = NULL;
lapack_int LAPACKE_sggesx_work(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_S_SELECT3            selctg,
    char            sense,
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
    float *            rconde,
    float *            rcondv,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_sggesx_work==NULL) {
        _g_LAPACKE_sggesx_work = rindow_load_libopenblas_func("LAPACKE_sggesx_work"); 
        if(_g_LAPACKE_sggesx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggesx_work(
        matrix_layout,
        jobvsl,
        jobvsr,
        sort,
        selctg,
        sense,
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
        rconde,
        rcondv,
        work,
        lwork,
        iwork,
        liwork,
        bwork    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeesx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeesx_work)( /* LAPACKE_sgeesx_work */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_S_SELECT2            /* select */,
    char            /* sense */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    float *            /* wr */,
    float *            /* wi */,
    float *            /* vs */,
    lapack_int            /* ldvs */,
    float *            /* rconde */,
    float *            /* rcondv */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_sgeesx_work _g_LAPACKE_sgeesx_work = NULL;
lapack_int LAPACKE_sgeesx_work(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_S_SELECT2            select,
    char            sense,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    float *            wr,
    float *            wi,
    float *            vs,
    lapack_int            ldvs,
    float *            rconde,
    float *            rcondv,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_sgeesx_work==NULL) {
        _g_LAPACKE_sgeesx_work = rindow_load_libopenblas_func("LAPACKE_sgeesx_work"); 
        if(_g_LAPACKE_sgeesx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeesx_work(
        matrix_layout,
        jobvs,
        sort,
        select,
        sense,
        n,
        a,
        lda,
        sdim,
        wr,
        wi,
        vs,
        ldvs,
        rconde,
        rcondv,
        work,
        lwork,
        iwork,
        liwork,
        bwork    
    );
}

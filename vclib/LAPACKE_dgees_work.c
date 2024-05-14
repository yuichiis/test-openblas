#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgees_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgees_work)( /* LAPACKE_dgees_work */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_D_SELECT2            /* select */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    double *            /* wr */,
    double *            /* wi */,
    double *            /* vs */,
    lapack_int            /* ldvs */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_dgees_work _g_LAPACKE_dgees_work = NULL;
lapack_int LAPACKE_dgees_work(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_D_SELECT2            select,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    double *            wr,
    double *            wi,
    double *            vs,
    lapack_int            ldvs,
    double *            work,
    lapack_int            lwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_dgees_work==NULL) {
        _g_LAPACKE_dgees_work = rindow_load_libopenblas_func("LAPACKE_dgees_work"); 
        if(_g_LAPACKE_dgees_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgees_work(
        matrix_layout,
        jobvs,
        sort,
        select,
        n,
        a,
        lda,
        sdim,
        wr,
        wi,
        vs,
        ldvs,
        work,
        lwork,
        bwork    
    );
}

#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgees_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgees_work)( /* LAPACKE_cgees_work */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_C_SELECT1            /* select */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    lapack_complex_float *            /* w */,
    lapack_complex_float *            /* vs */,
    lapack_int            /* ldvs */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_cgees_work _g_LAPACKE_cgees_work = NULL;
lapack_int LAPACKE_cgees_work(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_C_SELECT1            select,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    lapack_complex_float *            w,
    lapack_complex_float *            vs,
    lapack_int            ldvs,
    lapack_complex_float *            work,
    lapack_int            lwork,
    float *            rwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_cgees_work==NULL) {
        _g_LAPACKE_cgees_work = rindow_load_libopenblas_func("LAPACKE_cgees_work"); 
        if(_g_LAPACKE_cgees_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgees_work(
        matrix_layout,
        jobvs,
        sort,
        select,
        n,
        a,
        lda,
        sdim,
        w,
        vs,
        ldvs,
        work,
        lwork,
        rwork,
        bwork    
    );
}

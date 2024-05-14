#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztpmqrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztpmqrt_work)( /* LAPACKE_ztpmqrt_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    lapack_int            /* nb */,
    const lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    const lapack_complex_double *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_ztpmqrt_work _g_LAPACKE_ztpmqrt_work = NULL;
lapack_int LAPACKE_ztpmqrt_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    lapack_int            nb,
    const lapack_complex_double *            v,
    lapack_int            ldv,
    const lapack_complex_double *            t,
    lapack_int            ldt,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_ztpmqrt_work==NULL) {
        _g_LAPACKE_ztpmqrt_work = rindow_load_libopenblas_func("LAPACKE_ztpmqrt_work"); 
        if(_g_LAPACKE_ztpmqrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztpmqrt_work(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        l,
        nb,
        v,
        ldv,
        t,
        ldt,
        a,
        lda,
        b,
        ldb,
        work    
    );
}
